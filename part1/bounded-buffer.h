/*
 * Sanhu Li
 * Oct. 14, 2014
 * CS 441/541: Bounded Buffer (Project 2 Part 1)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include "semaphore_support.h"
#include "stdbool.h"
#include "string.h"
#include "ctype.h"

/*****************************
* Defines
*****************************/
#define RAND_MIN 0
#define RAND_RAN 10
#define WAIT_MOST 1000000

/*****************************
* Structures
*****************************/


/*****************************
* Global Variables
*****************************/
//  sem_c: semaphore for consumers, should be initialized to 0
semaphore_t sem_c;
//  sem_p: semaphore for producers, should be initialized to BUFFER_SIZE
semaphore_t sem_p;
//  buffer to store values
int *buffer;
//  buffer size default to be 10
int BUFFER_SIZE = 10;
//  current read position and write position
int r, w;
//  printf mutex
pthread_mutex_t p_mutex = PTHREAD_MUTEX_INITIALIZER;
//
int p_count = 0, c_count = 0;

/*****************************
* Function Declarations
*****************************/
/**
* insert a value into the buffer, with a mutex lock
* val: the value to be inserted
*/
bool insert(int val);

/**
* read a value from the buffer, then delete it, with a mutex lock
*/
int read_remove();

/**
* consumer threads function
*/
void *consumer(void *param);

/**
* producer threads function
*/
void *producer(void *param);

/**
* Called when receive error inputs
*/
void wrong_params();

/**
* Judge whether input string str is a valid integer
* str: The string to be judged
*/
bool isInteger(const char * str);

/**
* Start processing the problem after parsing the input params
*/
void process(int live, int p_num, int c_num, int b_size);

char * buf_to_str(const int * buf);

