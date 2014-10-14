# CS441/541 Project 02 - Part 1
**Author:** *Huifeng Zhang, Sanhu Li*

**Date:** *Oct. 14, 2014*

---
## Description:

It is a program solution to the bounded-buffer problem.

By specifyiny the numbers of buffer size b, time to live t , producers p and consumers c, the program will automatically generate a solution to execute in a b size buffer metric with p producing values and c consumes values in time period of t without making either p or c sleeping for unbounded amount of time.

---
## How to compile:
A Makefile is provided in this assignment.
To compile the application, use the command:
```
$ make
```

To remove the application, please use:
```
$ make clean
```
---
## How to run:

To run the program from the command line, simply execute the following command just as you did to run other programs before
```
$ ./bouned-buffer t p c [b]
```
while t, p, c, b are input by user which stands for the numbers of time, producer, consumer and buffer size sequentially. And b can be left empty and in that case the buffer size will be defaulted to be 10, as shown below.
```
$ ./bouned-buffer t p c 
```
---
## Example(s):
This example runs with a simple input command `./bounded-buffer 2 2 1 4`.(note: That the results generate will differ from each time running as values and sequences are randomly generated.)

```
Buffer Size               :   4
Time To Live (seconds)    :   2
Number of Producer threads:   2
Number of Consumer threads:   1
-------------------------------
Initial Buffer:                 	[  -1v^  -1  -1  -1]
Producer  0: Total   1, Value   6	[   6v  -1^  -1  -1]
Producer  0: Total   2, Value   6	[   6v   6  -1^  -1]
Producer  1: Total   3, Value   5	[   6v   6   5  -1^]
Consumer  0: Total   1, Value   6	[  -1   6v   5  -1^]
Consumer  0: Total   2, Value   6	[  -1  -1   5v  -1^]
Producer  0: Total   4, Value   9	[  -1^  -1   5v   9]
Producer  1: Total   5, Value   2	[   2  -1^   5v   9]
Consumer  0: Total   3, Value   5	[   2  -1^  -1   9v]
Producer  0: Total   6, Value   3	[   2   3  -1^   9v]
Producer  1: Total   7, Value   0	[   2   3   0   9v^]
Consumer  0: Total   4, Value   9	[   2v   3   0   9^]
Producer  1: Total   8, Value   8	[   2v^   3   0   8]
-----------+---------
Produced   |    8
Consumed   |    4
-----------+---------
```
This example runs with a simple input command `./bounded-buffer 5 4 3`, by left buffer size empty, the program will default it to be 10 and execute.

```
Buffer Size               :  10
Time To Live (seconds)    :   5
Number of Producer threads:   4
Number of Consumer threads:   3
-------------------------------
Initial Buffer:                 	[  -1v^  -1  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   1, Value   6	[   6v  -1^  -1  -1  -1  -1  -1  -1  -1  -1]
Consumer  2: Total   1, Value   6	[  -1  -1v^  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  1: Total   2, Value   5	[  -1   5v  -1^  -1  -1  -1  -1  -1  -1  -1]
Consumer  0: Total   2, Value   5	[  -1  -1  -1v^  -1  -1  -1  -1  -1  -1  -1]
Producer  2: Total   3, Value   5	[  -1  -1   5v  -1^  -1  -1  -1  -1  -1  -1]
Consumer  1: Total   3, Value   5	[  -1  -1  -1  -1v^  -1  -1  -1  -1  -1  -1]
Producer  0: Total   4, Value   0	[  -1  -1  -1   0v  -1^  -1  -1  -1  -1  -1]
Producer  0: Total   5, Value   8	[  -1  -1  -1   0v   8  -1^  -1  -1  -1  -1]
Consumer  2: Total   4, Value   0	[  -1  -1  -1  -1   8v  -1^  -1  -1  -1  -1]
Consumer  0: Total   5, Value   8	[  -1  -1  -1  -1  -1  -1v^  -1  -1  -1  -1]
Producer  3: Total   6, Value   2	[  -1  -1  -1  -1  -1   2v  -1^  -1  -1  -1]
Consumer  0: Total   6, Value   2	[  -1  -1  -1  -1  -1  -1  -1v^  -1  -1  -1]
Producer  2: Total   7, Value   2	[  -1  -1  -1  -1  -1  -1   2v  -1^  -1  -1]
Consumer  0: Total   7, Value   2	[  -1  -1  -1  -1  -1  -1  -1  -1v^  -1  -1]
Producer  0: Total   8, Value   9	[  -1  -1  -1  -1  -1  -1  -1   9v  -1^  -1]
Consumer  1: Total   8, Value   9	[  -1  -1  -1  -1  -1  -1  -1  -1  -1v^  -1]
Producer  1: Total   9, Value   6	[  -1  -1  -1  -1  -1  -1  -1  -1   6v  -1^]
Consumer  2: Total   9, Value   6	[  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1v^]
Producer  3: Total  10, Value   3	[  -1^  -1  -1  -1  -1  -1  -1  -1  -1   3v]
Consumer  2: Total  10, Value   3	[  -1v^  -1  -1  -1  -1  -1  -1  -1  -1   3]
Producer  3: Total  11, Value   2	[   2v  -1^  -1  -1  -1  -1  -1  -1  -1   3]
Consumer  1: Total  11, Value   2	[  -1  -1v^  -1  -1  -1  -1  -1  -1  -1   3]
Producer  2: Total  12, Value   9	[  -1   9v  -1^  -1  -1  -1  -1  -1  -1   3]
Consumer  2: Total  12, Value   9	[  -1  -1  -1v^  -1  -1  -1  -1  -1  -1   3]
Producer  0: Total  13, Value   8	[  -1  -1   8v  -1^  -1  -1  -1  -1  -1   3]
Consumer  0: Total  13, Value   8	[  -1  -1  -1  -1v^  -1  -1  -1  -1  -1   3]
Producer  3: Total  14, Value   1	[  -1  -1  -1   1v  -1^  -1  -1  -1  -1   3]
Producer  2: Total  15, Value   7	[  -1  -1  -1   1v   7  -1^  -1  -1  -1   3]
Consumer  1: Total  14, Value   1	[  -1  -1  -1  -1   7v  -1^  -1  -1  -1   3]
Consumer  2: Total  15, Value   7	[  -1  -1  -1  -1  -1  -1v^  -1  -1  -1   3]
Producer  1: Total  16, Value   3	[  -1  -1  -1  -1  -1   3v  -1^  -1  -1   3]
Consumer  2: Total  16, Value   3	[  -1  -1  -1  -1  -1  -1  -1v^  -1  -1   3]
Producer  0: Total  17, Value   5	[  -1  -1  -1  -1  -1  -1   5v  -1^  -1   3]
Producer  3: Total  18, Value   6	[  -1  -1  -1  -1  -1  -1   5v   6  -1^   3]
Consumer  0: Total  17, Value   5	[  -1  -1  -1  -1  -1  -1  -1   6v  -1^   3]
Producer  2: Total  19, Value   0	[  -1  -1  -1  -1  -1  -1  -1   6v   0   3^]
Consumer  1: Total  18, Value   6	[  -1  -1  -1  -1  -1  -1  -1  -1   0v   3^]
Consumer  0: Total  19, Value   0	[  -1  -1  -1  -1  -1  -1  -1  -1  -1   3v^]
Producer  3: Total  20, Value   4	[  -1^  -1  -1  -1  -1  -1  -1  -1  -1   4v]
Producer  0: Total  21, Value   5	[   5  -1^  -1  -1  -1  -1  -1  -1  -1   4v]
Producer  1: Total  22, Value   0	[   5   0  -1^  -1  -1  -1  -1  -1  -1   4v]
Consumer  2: Total  20, Value   4	[   5v   0  -1^  -1  -1  -1  -1  -1  -1   4]
Producer  2: Total  23, Value   5	[   5v   0   5  -1^  -1  -1  -1  -1  -1   4]
Consumer  0: Total  21, Value   5	[  -1   0v   5  -1^  -1  -1  -1  -1  -1   4]
Producer  3: Total  24, Value   7	[  -1   0v   5   7  -1^  -1  -1  -1  -1   4]
Producer  0: Total  25, Value   5	[  -1   0v   5   7   5  -1^  -1  -1  -1   4]
Consumer  1: Total  22, Value   0	[  -1  -1   5v   7   5  -1^  -1  -1  -1   4]
Producer  2: Total  26, Value   4	[  -1  -1   5v   7   5   4  -1^  -1  -1   4]
Consumer  1: Total  23, Value   5	[  -1  -1  -1   7v   5   4  -1^  -1  -1   4]
Producer  0: Total  27, Value   8	[  -1  -1  -1   7v   5   4   8  -1^  -1   4]
Producer  1: Total  28, Value   5	[  -1  -1  -1   7v   5   4   8   5  -1^   4]
Producer  3: Total  29, Value   0	[  -1  -1  -1   7v   5   4   8   5   0   4^]
Consumer  1: Total  24, Value   7	[  -1  -1  -1  -1   5v   4   8   5   0   4^]
Consumer  2: Total  25, Value   5	[  -1  -1  -1  -1  -1   4v   8   5   0   4^]
Producer  1: Total  30, Value   9	[  -1^  -1  -1  -1  -1   4v   8   5   0   9]
Producer  0: Total  31, Value   1	[   1  -1^  -1  -1  -1   4v   8   5   0   9]
Consumer  0: Total  26, Value   4	[   1  -1^  -1  -1  -1  -1   8v   5   0   9]
Producer  2: Total  32, Value   8	[   1   8  -1^  -1  -1  -1   8v   5   0   9]
Consumer  1: Total  27, Value   8	[   1   8  -1^  -1  -1  -1  -1   5v   0   9]
-----------+---------
Produced   |   32
Consumed   |   27
-----------+---------

```
---
## How do I test

# test case 1 
-- to test if the program displays correct error message when input less or more parameters than expected
```
./bounded-buffer 
```
should display
```
 "wrong parameters
Usage: time_to_live(seconds) producer_number consumer_number [buffer_size]"
```
err message displayed as expected

```
./bounded-buffer 2
```
should display
```
 "wrong parameters
Usage: time_to_live(seconds) producer_number consumer_number [buffer_size]"
```
err message displayed as expected

```
./bounded-buffer 2 2
```
should display
```
 "wrong parameters
Usage: time_to_live(seconds) producer_number consumer_number [buffer_size]"
```
err message displayed as expected

```
./bounded-buffer 2 2 2
```
should display
```
 the results of execution correctly.
results displayed as expected

```
./bounded-buffer 2 2 2 2
```
should display
```
 the results of execution correctly.
results displayed as expected
```
./bounded-buffer 2 2 2 2 2
```
should display
```
 "wrong parameters
Usage: time_to_live(seconds) producer_number consumer_number [buffer_size]"
```
err message displayed as expected


# test case 2
-- to test if the program displays correct error message when input invalid characters

```
./bounded-buffer  - - - -
```
```
./bounded-buffer a a a a
```
```
./bounded-buffer  	 	a
```
```
./bounded-buffer -1 -2 -2 -2
```
should display
```
 "wrong parameters
Usage: time_to_live(seconds) producer_number consumer_number [buffer_size]"
```
err message displayed as expected

# test case 3
-- to test if the program executes correctly when input 0 producer
```
./bounded-buffer 5 0 5 10
```
shoud display the execution results which there is no producer or consumer thread because consumers can't consume if there is no product produced by 0 producer.

display:
```
Buffer Size               :  10
Time To Live (seconds)    :   5
Number of Producer threads:   0
Number of Consumer threads:   5
-------------------------------
Initial Buffer:                 	[  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1]
-----------+---------
Produced   |    0
Consumed   |    0
-----------+---------
```
correct.

# test case 4
-- to test if the program executes correctly when input 0 consumer, and if the producers rewrite the buffer while product is already in there and not consumed.
```
./bounded-buffer 5 5 0 10
```
shoud display the execution results while there is no consumer thread because there is no consumer to consume the products.
display:
```
Buffer Size               :  10
Time To Live (seconds)    :   5
Number of Producer threads:   5
Number of Consumer threads:   0
-------------------------------
Initial Buffer:                 	[  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   1, Value   6	[   6v  -1^  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   2, Value   7	[   6v   7  -1^  -1  -1  -1  -1  -1  -1  -1]
Producer  4: Total   3, Value   1	[   6v   7   1  -1^  -1  -1  -1  -1  -1  -1]
Producer  1: Total   4, Value   5	[   6v   7   1   5  -1^  -1  -1  -1  -1  -1]
Producer  2: Total   5, Value   5	[   6v   7   1   5   5  -1^  -1  -1  -1  -1]
Producer  2: Total   6, Value   6	[   6v   7   1   5   5   6  -1^  -1  -1  -1]
Producer  2: Total   7, Value   8	[   6v   7   1   5   5   6   8  -1^  -1  -1]
Producer  0: Total   8, Value   9	[   6v   7   1   5   5   6   8   9  -1^  -1]
Producer  1: Total   9, Value   6	[   6v   7   1   5   5   6   8   9   6  -1^]
Producer  3: Total  10, Value   2	[   6^v   7   1   5   5   6   8   9   6   2]
-----------+---------
Produced   |   10
Consumed   |    0
-----------+---------
```
correct.

# test case 5
-- to test if the program executes correctly when input 0 buffer_size
```
./bounded-buffer 2 2 2 0
```
should display error message
displays:
```
"Please enter valid numbers
Wrong parameters
Usage: time_to_live(seconds) producer_number consumer_number [buffer_size]"
```
err message displayed as expected

# test case 6
-- to test if the program executes correctly when input 0 time period
```
./bounded-buffer 0 5 5 10
```

should display
```
 only the initial buffer and show the results with 0 produced and consumed because no time for prodecers and consumers to execute.
display:
```
Buffer Size               :  10
Time To Live (seconds)    :   0
Number of Producer threads:   5
Number of Consumer threads:   5
-------------------------------
Initial Buffer:                 	[  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1]
-----------+---------
Produced   |    0
Consumed   |    0
-----------+---------
```
correct.

# test case 7
-- to test if the program works properly when there are more producers than consumers, by going through line by line to see if the "total" of consumed is less than or equal to that of produced.
```
./bounded-buffer 5 5 2 10
```
display:
```
Buffer Size               :  10
Time To Live (seconds)    :   5
Number of Producer threads:   5
Number of Consumer threads:   2
-------------------------------
Initial Buffer:                 	[  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   1, Value   6	[   6v  -1^  -1  -1  -1  -1  -1  -1  -1  -1]
Consumer  0: Total   1, Value   6	[  -1  -1^v  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  4: Total   2, Value   1	[  -1   1v  -1^  -1  -1  -1  -1  -1  -1  -1]
Consumer  1: Total   2, Value   1	[  -1  -1  -1^v  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   3, Value   9	[  -1  -1   9v  -1^  -1  -1  -1  -1  -1  -1]
Producer  1: Total   4, Value   5	[  -1  -1   9v   5  -1^  -1  -1  -1  -1  -1]
Producer  1: Total   5, Value   8	[  -1  -1   9v   5   8  -1^  -1  -1  -1  -1]
Producer  2: Total   6, Value   5	[  -1  -1   9v   5   8   5  -1^  -1  -1  -1]
Producer  0: Total   7, Value   6	[  -1  -1   9v   5   8   5   6  -1^  -1  -1]
Producer  3: Total   8, Value   2	[  -1  -1   9v   5   8   5   6   2  -1^  -1]
Consumer  1: Total   3, Value   9	[  -1  -1  -1   5v   8   5   6   2  -1^  -1]
Producer  4: Total   9, Value   0	[  -1  -1  -1   5v   8   5   6   2   0  -1^]
Producer  3: Total  10, Value   5	[  -1^  -1  -1   5v   8   5   6   2   0   5]
Consumer  0: Total   4, Value   5	[  -1^  -1  -1  -1   8v   5   6   2   0   5]
Producer  2: Total  11, Value   0	[   0  -1^  -1  -1   8v   5   6   2   0   5]
Producer  1: Total  12, Value   9	[   0   9  -1^  -1   8v   5   6   2   0   5]
Consumer  1: Total   5, Value   8	[   0   9  -1^  -1  -1   5v   6   2   0   5]
Producer  0: Total  13, Value   3	[   0   9   3  -1^  -1   5v   6   2   0   5]
Producer  1: Total  14, Value   2	[   0   9   3   2  -1^   5v   6   2   0   5]
Consumer  1: Total   6, Value   5	[   0   9   3   2  -1^  -1   6v   2   0   5]
Producer  3: Total  15, Value   9	[   0   9   3   2   9  -1^   6v   2   0   5]
Producer  0: Total  16, Value   1	[   0   9   3   2   9   1   6^v   2   0   5]
Consumer  0: Total   7, Value   6	[   0   9   3   2   9   1  -1^   2v   0   5]
Producer  4: Total  17, Value   2	[   0   9   3   2   9   1   2   2^v   0   5]
Consumer  1: Total   8, Value   2	[   0   9   3   2   9   1   2  -1^   0v   5]
Producer  1: Total  18, Value   4	[   0   9   3   2   9   1   2   4   0^v   5]
Consumer  0: Total   9, Value   0	[   0   9   3   2   9   1   2   4  -1^   5v]
Producer  2: Total  19, Value   6	[   0   9   3   2   9   1   2   4   6   5^v]
Consumer  1: Total  10, Value   5	[   0v   9   3   2   9   1   2   4   6  -1^]
Producer  3: Total  20, Value   4	[   0^v   9   3   2   9   1   2   4   6   4]
Consumer  1: Total  11, Value   0	[  -1^   9v   3   2   9   1   2   4   6   4]
Producer  0: Total  21, Value   0	[   0   9^v   3   2   9   1   2   4   6   4]
Consumer  0: Total  12, Value   9	[   0  -1^   3v   2   9   1   2   4   6   4]
Producer  1: Total  22, Value   6	[   0   6   3^v   2   9   1   2   4   6   4]
Consumer  0: Total  13, Value   3	[   0   6  -1^   2v   9   1   2   4   6   4]
Producer  4: Total  23, Value   1	[   0   6   1   2^v   9   1   2   4   6   4]
Consumer  1: Total  14, Value   2	[   0   6   1  -1^   9v   1   2   4   6   4]
Producer  3: Total  24, Value   5	[   0   6   1   5   9^v   1   2   4   6   4]
Consumer  1: Total  15, Value   9	[   0   6   1   5  -1^   1v   2   4   6   4]
Producer  0: Total  25, Value   7	[   0   6   1   5   7   1^v   2   4   6   4]
Consumer  0: Total  16, Value   1	[   0   6   1   5   7  -1^   2v   4   6   4]
Producer  2: Total  26, Value   6	[   0   6   1   5   7   6   2^v   4   6   4]
Consumer  1: Total  17, Value   2	[   0   6   1   5   7   6  -1^   4v   6   4]
Producer  3: Total  27, Value   2	[   0   6   1   5   7   6   2   4^v   6   4]
Consumer  1: Total  18, Value   4	[   0   6   1   5   7   6   2  -1^   6v   4]
Producer  1: Total  28, Value   9	[   0   6   1   5   7   6   2   9   6^v   4]
Consumer  1: Total  19, Value   6	[   0   6   1   5   7   6   2   9  -1^   4v]
Producer  4: Total  29, Value   4	[   0   6   1   5   7   6   2   9   4   4^v]
-----------+---------
Produced   |   29
Consumed   |   19
-----------+---------
```
correct.

# test case 8 
-- to test if the program works properly when there are more producers than consumers, by going through line by line to see if the "total" of consumed is less than or equal to that of produced.
```
./bounded-buffer 5 2 5 10
```
display:
```
Buffer Size               :  10
Time To Live (seconds)    :   5
Number of Producer threads:   2
Number of Consumer threads:   5
-------------------------------
Initial Buffer:                 	[  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   1, Value   6	[   6v  -1^  -1  -1  -1  -1  -1  -1  -1  -1]
Consumer  1: Total   1, Value   6	[  -1  -1^v  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  1: Total   2, Value   5	[  -1   5v  -1^  -1  -1  -1  -1  -1  -1  -1]
Consumer  4: Total   2, Value   5	[  -1  -1  -1^v  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   3, Value   2	[  -1  -1   2v  -1^  -1  -1  -1  -1  -1  -1]
Consumer  0: Total   3, Value   2	[  -1  -1  -1  -1^v  -1  -1  -1  -1  -1  -1]
Producer  1: Total   4, Value   9	[  -1  -1  -1   9v  -1^  -1  -1  -1  -1  -1]
Consumer  3: Total   4, Value   9	[  -1  -1  -1  -1  -1^v  -1  -1  -1  -1  -1]
Producer  1: Total   5, Value   6	[  -1  -1  -1  -1   6v  -1^  -1  -1  -1  -1]
Consumer  1: Total   5, Value   6	[  -1  -1  -1  -1  -1  -1^v  -1  -1  -1  -1]
Producer  0: Total   6, Value   0	[  -1  -1  -1  -1  -1   0v  -1^  -1  -1  -1]
Consumer  2: Total   6, Value   0	[  -1  -1  -1  -1  -1  -1  -1^v  -1  -1  -1]
Producer  1: Total   7, Value   7	[  -1  -1  -1  -1  -1  -1   7v  -1^  -1  -1]
Consumer  3: Total   7, Value   7	[  -1  -1  -1  -1  -1  -1  -1  -1^v  -1  -1]
Producer  0: Total   8, Value   0	[  -1  -1  -1  -1  -1  -1  -1   0v  -1^  -1]
Consumer  0: Total   8, Value   0	[  -1  -1  -1  -1  -1  -1  -1  -1  -1^v  -1]
Producer  1: Total   9, Value   7	[  -1  -1  -1  -1  -1  -1  -1  -1   7v  -1^]
Consumer  4: Total   9, Value   7	[  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1^v]
Producer  0: Total  10, Value   2	[  -1^  -1  -1  -1  -1  -1  -1  -1  -1   2v]
Consumer  1: Total  10, Value   2	[  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  1: Total  11, Value   9	[   9v  -1^  -1  -1  -1  -1  -1  -1  -1  -1]
Consumer  2: Total  11, Value   9	[  -1  -1^v  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total  12, Value   6	[  -1   6v  -1^  -1  -1  -1  -1  -1  -1  -1]
Consumer  3: Total  12, Value   6	[  -1  -1  -1^v  -1  -1  -1  -1  -1  -1  -1]
Producer  1: Total  13, Value   9	[  -1  -1   9v  -1^  -1  -1  -1  -1  -1  -1]
Consumer  0: Total  13, Value   9	[  -1  -1  -1  -1^v  -1  -1  -1  -1  -1  -1]
Producer  0: Total  14, Value   9	[  -1  -1  -1   9v  -1^  -1  -1  -1  -1  -1]
Consumer  1: Total  14, Value   9	[  -1  -1  -1  -1  -1^v  -1  -1  -1  -1  -1]
Producer  1: Total  15, Value   8	[  -1  -1  -1  -1   8v  -1^  -1  -1  -1  -1]
Consumer  4: Total  15, Value   8	[  -1  -1  -1  -1  -1  -1^v  -1  -1  -1  -1]
Producer  0: Total  16, Value   0	[  -1  -1  -1  -1  -1   0v  -1^  -1  -1  -1]
Consumer  2: Total  16, Value   0	[  -1  -1  -1  -1  -1  -1  -1^v  -1  -1  -1]
-----------+---------
Produced   |   16
Consumed   |   16
-----------+---------
```

correct.

---

## Known bugs & limitations:

If you find any bugs, please report to [li.sanh@uwlax.edu](mailto:li.sanh@uwlax.edu) or [zhang.huif@uwlax.edu](mailto:zhang.huif@uwlax.edu)



