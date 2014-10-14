/*
 * Sanhu Li
 * Oct. 14, 2014
 * CS 441/541: Bounded Buffer (Project 2 Part 1)
 *
 */
#include "bounded-buffer.h"

int * parse_input_params(int argc, char *argv[]) {
    int i, *params;

    params = (int *) malloc(sizeof(int) * 4);
    params[3] = 10;
    for (i = 1; i < argc; ++i) {
        if (!isInteger(argv[i])) {
            wrong_params();
            exit(0);
        } else {
            params[i - 1] = strtol(argv[i], NULL, 10);
        }
    }
    BUFFER_SIZE = params[3];

    return params;
}

int main(int argc, char * argv[]) {
    int *params;

    /**
    * parameters in the form of:
    * time_to_live(seconds) producer_number consumer_number [buffer_size]
    */
    if (4 == argc || 5 == argc) {
        params = parse_input_params(argc, argv);
        process(params[0], params[1], params[2], params[3]);
    } else {
        wrong_params();
    }

    return 0;
}

bool insert(int val) {
//    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//
//    pthread_mutex_lock(&mutex);
    buffer[w++] = val;
    while (w >= BUFFER_SIZE) {
        w -= BUFFER_SIZE;
    }
//    pthread_mutex_unlock(&mutex);
    return true;
}

int read_remove() {
    int val;
//    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//    pthread_mutex_lock(&mutex);
    val = buffer[r++];
    while (r >= BUFFER_SIZE) {
        r -= BUFFER_SIZE;
    }
    buffer[r - 1] = -1;
//    pthread_mutex_unlock(&mutex);

    return val;
}

void *consumer(void *param) {
    int t_no = (intptr_t)param;
    int v, t;

    while (true) {
        t = random() % WAIT_MOST;

        usleep(t);
        semaphore_wait(&sem_c);
        pthread_mutex_lock(&p_mutex);

        v = read_remove();
        printf("Consumer %2d: Total %3d, Value %3d\t%s\n", t_no, ++c_count, v, buf_to_str(buffer));
        fflush(NULL);
        pthread_mutex_unlock(&p_mutex);
        semaphore_post(&sem_p);
    }

    return NULL;
}

void *producer(void *param) {
    int t_no = (intptr_t)param;
    int v, t;

    while (true) {
        t = random() % WAIT_MOST;
        v = random() % RAND_RAN + RAND_MIN;

        usleep(t);
        semaphore_wait(&sem_p);
        pthread_mutex_lock(&p_mutex);

        insert(v);
        printf("Producer %2d: Total %3d, Value %3d\t%s\n", t_no, ++p_count, v, buf_to_str(buffer));
        fflush(NULL);
        pthread_mutex_unlock(&p_mutex);
        semaphore_post(&sem_c);
    }

    return NULL;
}

void wrong_params() {
    printf("Wrong parameters\n");
    printf("Usage: time_to_live(seconds) producer_number consumer_number [buffer_size]\n");
}

bool isInteger(const char *str) {
    size_t len = strlen(str);
    int i;

    for (i = 0; i < len; ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void process(int live, int p_num, int c_num, int b_size) {
    int ret, i;
    pthread_t *c_threads, *p_threads;

    if (live < 0 || p_num < 0 || c_num < 0 || b_size <= 0) {
        printf("Please enter valid numbers\n");
        wrong_params();
        exit(-1);
    }

    if (0 != (ret = semaphore_create(&sem_p, b_size))) {
        fprintf(stderr, "Error: lib_semaphore_create() failed with %d\n", ret);
        exit(-1);
    }

    if (0 != (ret = semaphore_create(&sem_c, 0))) {
        fprintf(stderr, "Error: lib_semaphore_create() failed with %d\n", ret);
        exit(-1);
    }

    buffer = (int *) malloc(sizeof(int) * b_size);
    c_threads = (pthread_t *) malloc(sizeof(pthread_t) * c_num);
    p_threads = (pthread_t *) malloc(sizeof(pthread_t) * p_num);

    for (i = 0; i < b_size; ++i) {
        buffer[i] = -1;
    }

    printf("Buffer Size               :%4d\n", b_size);
    printf("Time To Live (seconds)    :%4d\n", live);
    printf("Number of Producer threads:%4d\n", p_num);
    printf("Number of Consumer threads:%4d\n", c_num);
    printf("-------------------------------\n");
    printf("Initial Buffer:                 \t%s\n", buf_to_str(buffer));
    fflush(stdout);
    sleep(2);

    for (i = 0; i < p_num; ++i) {
        ret = pthread_create(&p_threads[i], NULL, producer, (void *)(intptr_t)i);
        if (0 != ret) {
            fprintf(stderr, "Error: Cannot Create thread\n");
            exit(-1);
        }
    }

    for (i = 0; i < c_num; ++i) {
        ret = pthread_create(&c_threads[i], NULL, consumer, (void *)(intptr_t)i);
        if (0 != ret) {
            fprintf(stderr, "Error: Cannot Create thread\n");
            exit(-1);
        }
    }

    sleep(live);

    for (i = 0; i < p_num; ++i) {
        pthread_cancel(p_threads[i]);
    }

    for (i = 0; i < c_num; ++i) {
        pthread_cancel(c_threads[i]);
    }

    printf("-----------+---------\n");
    printf("Produced   | %4d\n", p_count);
    printf("Consumed   | %4d\n", c_count);
    printf("-----------+---------\n");
    fflush(NULL);
}

char *buf_to_str(const int *buf) {
    int i;
    char *str, tmp[5];
    str = (char *) malloc(sizeof(char) * 8 * BUFFER_SIZE);
    int rr = r, ww = w;

    sprintf(str, "[");
    for (i = 0; i < BUFFER_SIZE; ++i) {
        sprintf(tmp, "%4d", buf[i]);
        strcat(str, tmp);
        if (rr == i) {
            sprintf(tmp, "v");
            strcat(str, tmp);
        }

        if (ww == i) {
            sprintf(tmp, "^");
            strcat(str, tmp);
        }

    }
    sprintf(tmp, "]");
    strcat(str, tmp);
    return str;
}
