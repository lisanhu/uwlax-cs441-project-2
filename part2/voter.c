/*
 *
 * Author: Sanhu Li
 * CS 441/541: Finicky Voter (Assignment 2 Part 2)
 * Oct. 20, 2014
 */
#include "voter.h"

int main(int argc, char *argv[]) {

    int nums[4] = {10, 5, 5, 5};
    int i;

    if (argc <= 5) {
        for (i = 1; i < argc; ++i) {
            nums[i - 1] = strtol(argv[i], NULL, 10);
        }

        num_booth = nums[0];
        num_repub = nums[1];
        num_democ = nums[2];
        num_indep = nums[3];
        start_booth();
    } else {
        usage();
    }

    return 0;
}

void usage() {
    printf("Usage:\n");
    printf("./start_booth [booth num] [repub num] [democ num] [indep num]\n");
    fflush(stdout);
}


void start_booth() {
    int before_open = 2;
    long total = num_repub + num_democ + num_indep;
    int i;

    which = 'I';
    // voters in sequence: rep, dem, ind
    pthread_t *voters = (pthread_t *) malloc(sizeof(pthread_t) * total);
    voter_t *confs = (voter_t *) malloc(sizeof(voter_t) * total);
    repub_q = (int *) malloc(sizeof(int) * num_repub);
    democ_q = (int *) malloc(sizeof(int) * num_democ);
    indep_q = (int *) malloc(sizeof(int) * num_indep);

    booth = (char *) malloc(sizeof(char) * num_booth);
    for (i = 0; i < num_booth; ++i) {
        booth[i] = '.';
    }

    semaphore_create(&sem_booth, num_booth);
    semaphore_create(&station_lock, 1);
    semaphore_create(&mutex, 1);
    semaphore_create(&lock, 1);
    semaphore_create(&q_lock, 1);
    srand(time(NULL));

    semaphore_wait(&station_lock);
    print_configure(num_booth, num_repub, num_democ, num_indep);

    /** Create voters **/
    for (i = 0; i < num_repub; ++i) {
        confs[i].id = i;
        confs[i].type = 'R';
        pthread_create(&voters[i], NULL, voter, (void *) &(confs[i]));
    }

    for (i = 0; i < num_democ; ++i) {
        int idx = i + num_repub;
        confs[idx].id = i;
        confs[idx].type = 'D';
        pthread_create(&voters[idx], NULL, voter, (void *) &(confs[idx]));
    }

    for (i = 0; i < num_indep; ++i) {
        int idx = i + num_repub + num_democ;
        confs[idx].id = i;
        confs[idx].type = 'I';
        pthread_create(&voters[idx], NULL, voter, (void *) &(confs[idx]));
    }
    /** Sleep a while **/
    sleep(before_open);
    print_slashes();
    semaphore_post(&station_lock);

    /** Wait until everyone finishes voting **/
    for (i = 0; i < total; ++i) {
        pthread_join(voters[i], NULL);
    }
    print_slashes();
    semaphore_destroy(&station_lock);
    semaphore_destroy(&sem_booth);
    semaphore_destroy(&lock);
    semaphore_destroy(&mutex);
    semaphore_destroy(&q_lock);
}

void *voter(void *arg) {
    voter_t v = *(voter_t *) arg;
    int regi_time = rand() % 50000, vote_time = rand() % 100000;
    char thread_name[25], thread_with_booth[25];
    char *message, *buf_str;
    int i;

    if ('I' == v.type) {
        sprintf(thread_name, "Independent %4d       ", v.id);
    } else if ('R' == v.type) {
        sprintf(thread_name, "Republican  %4d       ", v.id);
    } else if ('D' == v.type) {
        sprintf(thread_name, "Democrat    %4d       ", v.id);
    }

    /** Waiting in front of polling station **/
    message = "Waiting for polling station to open...";
    buf_str = buffer2str(booth, num_booth);
    printf("%s %s %s\n", thread_name, buf_str, message);
    free(buf_str);
    fflush(stdout);

    semaphore_wait(&station_lock);
    semaphore_post(&station_lock);

    /** The station opened **/
    message = "Entering the polling station";
    buf_str = buffer2str(booth, num_booth);
    printf("%s %s %s\n", thread_name, buf_str, message);
    free(buf_str);
    fflush(stdout);

    /** Registration **/
    usleep(regi_time);

    semaphore_wait(&q_lock);
    if ('I' == v.type) {
        add(indep_q, v.id, &i_e);
    } else if ('R' == v.type) {
        add(repub_q, v.id, &r_e);
    } else if ('D' == v.type) {
        add(democ_q, v.id, &d_e);
    }
    semaphore_post(&q_lock);

    /** Try entering a booth **/
    semaphore_wait(&sem_booth);

    if ('R' == v.type) {
        while (true) {
            semaphore_wait(&lock);
            if (findNo('D') && next(repub_q, r_s, r_e) == v.id) {
                if (d_e != d_s && findNo('R') && 'R' == which) {
                    semaphore_post(&lock);
                } else {
                    pop(repub_q, &r_s, &r_e);
                    which = 'R';
                    semaphore_post(&lock);
                    break;
                }
            } else {
                semaphore_post(&lock);
            }
        }
    }

    if ('D' == v.type) {
        while (true) {
            semaphore_wait(&lock);
            if (findNo('R') && next(democ_q, d_s, d_e) == v.id) {
                if (r_e != r_s && findNo('D') && 'D' == which) {
                    semaphore_post(&lock);
                } else {
                    pop(democ_q, &d_s, &d_e);
                    which = 'D';
                    semaphore_post(&lock);
                    break;
                }
            } else {
                semaphore_post(&lock);
            }
        }
    }

    if ('I' == v.type) {
        while (true) {
            semaphore_wait(&lock);
            if (next(indep_q, i_s, i_e) == v.id) {
                pop(indep_q, &i_s, &i_e);
                semaphore_post(&lock);
                break;
            } else {
                semaphore_post(&lock);
            }
        }
    }

    semaphore_wait(&mutex);
    i = findBooth();
    if (-1 != i) {
        booth[i] = v.type;
    } else {
        fprintf(stderr, "Error!!! Cannot find a booth!!!\n");
        exit(-1);
    }

    if ('I' == v.type) {
        sprintf(thread_with_booth, "Independent %4d in %2d ", v.id, i);
    } else if ('R' == v.type) {
        sprintf(thread_with_booth, "Republican  %4d in %2d ", v.id, i);
    } else if ('D' == v.type) {
        sprintf(thread_with_booth, "Democrat    %4d in %2d ", v.id, i);
    }

    message = "Voting!";
    buf_str = buffer2str(booth, num_booth);
    printf("%s %s %s\n", thread_with_booth, buf_str, message);
    free(buf_str);
    fflush(stdout);
    semaphore_post(&mutex);

    /** Voting process **/
    usleep(vote_time);

    /** Leaving the polling station **/

    semaphore_wait(&mutex);
    booth[i] = '.';

    message = "Leaving the polling station";
    buf_str = buffer2str(booth, num_booth);
    printf("%s %s %s\n", thread_name, buf_str, message);
    free(buf_str);
    fflush(stdout);
    semaphore_post(&mutex);
    semaphore_post(&sem_booth);

    return NULL;
}

void print_configure(const int booth, const int repub, const int democ, const int indep) {
    printf("Number of Voting Booths:%4d\n", booth);
    printf("Number of Republican   :%4d\n", repub);
    printf("Number of Democrat     :%4d\n", democ);
    printf("Number of Independent  :%4d\n", indep);
    print_slashes();
    fflush(stdout);
}

void print_slashes() {
    int len = num_booth * 3 + 9;
    int i;
    char slashes[len];

    for (i = 0; i < len; ++i) {
        slashes[i] = '-';
    }
    slashes[len - 1] = '\0';

    printf("------------------------+%s+--------------------------------\n", slashes);
}

char *buffer2str(char *buf, int num) {
    int len = num * 3 + 11;
    char str[len];
    int i;
    sprintf(str, "|->  ");
    for (i = 0; i < num; ++i) {
        sprintf(str, "%s[%c]", str, buf[i]);
    }
    sprintf(str, "%s  <-|", str);
    return strdup(str);
}

int findBooth() {
    int i;
    for (i = 0; i < num_booth; ++i) {
        if ('.' == booth[i]) {
            return i;
        }
    }
    return -1;
}

bool findNo(char type) {
    int i;
    for (i = 0; i < num_booth; ++i) {
        if (type == booth[i]) {
            return false;
        }
    }
    return true;
}

void add(int *queue, int val, int *end) {
    queue[(*end)++] = val;
}

int pop(int *queue, int *start, int *end) {
    int i;
    if (*start < *end) {
        i = (*start)++;
        return queue[i];
    } else {
        return -1;
    }
}

int next(int *queue, int start, int end) {
    if (start < end) {
        return queue[start];
    } else {
        return -1;
    }
}
