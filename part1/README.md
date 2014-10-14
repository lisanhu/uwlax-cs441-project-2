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

    $ make


To remove the application, please use:

    $ make clean

---
## How to run:

To run the program from the command line, simply execute the following command just as you did to run other programs before

    $ ./bouned-buffer t p c b

while t, p, c, b are input by user which stands for the numbers of time, producer, consumer and buffer size sequentially. And b can be left empty and in that case the buffer size will be defaulted to be 10.

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
## How to test:

type in the following command to test:

    make check

---

## Known bugs & limitations:

If you find any bugs, please report to [li.sanh@uwlax.edu](mailto:li.sanh@uwlax.edu) or [zhang.huif@uwlax.edu](mailto:zhang.huif@uwlax.edu)



