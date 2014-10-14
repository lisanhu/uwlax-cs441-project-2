# CS441/541 Project 01 - Part 2
**Author:** *Sanhu Li*

**Date:** *Oct. 14, 2014*

---
## Description:

This is a command line program aiming to solve the bounded-buffer problem

---
## How to compile:
A Makefile is provided in this assignment.
To compile the application, use the command:

$ make


To remove the application, please use:

$ make clean

---
## How to run:
To run the program, you need to type in the command line as follows:

```
$ ./bounded-buffer time-to-live num-of-producer num-of-consumer [buffer-size]
```

Note that the first three arguments must be greater than or equal to 0, and buffer-size is optional, which should be greater than 0.

---
## Example(s):
This example runs with a simple input command `$ ./bounded-buffer 3 3 1 2`.(note: when user run this command, the output may not be the same, because we don't know the order of the threads)

```
SanhudeMacBook-Pro:part1 lsh$ ./bounded-buffer 3 3 1 2
Buffer Size               :   2
Time To Live (seconds)    :   3
Number of Producer threads:   3
Number of Consumer threads:   1
-------------------------------
Initial Buffer:                 	[  -1v^  -1]
Producer  2: Total   1, Value   6	[   6v  -1^]
Producer  0: Total   2, Value   6	[   6v^   6]
Consumer  0: Total   1, Value   6	[  -1^   6v]
Producer  1: Total   3, Value   5	[   5   6v^]
Consumer  0: Total   2, Value   6	[   5v  -1^]
Producer  0: Total   4, Value   2	[   5v^   2]
Consumer  0: Total   3, Value   5	[  -1^   2v]
Producer  2: Total   5, Value   9	[   9   2v^]
Consumer  0: Total   4, Value   2	[   9v  -1^]
Producer  1: Total   6, Value   9	[   9v^   9]
Consumer  0: Total   5, Value   9	[  -1^   9v]
Producer  0: Total   7, Value   0	[   0   9v^]
-----------+---------
Produced   |    7
Consumed   |    5
-----------+---------
```
This example runs with a simple input command `$ ./bounded-buffer 3 3 10` to start the shell, user should input one command each time to process.

```
SanhudeMacBook-Pro:part1 lsh$ ./bounded-buffer 3 3 10
Buffer Size               :  10
Time To Live (seconds)    :   3
Number of Producer threads:   3
Number of Consumer threads:  10
-------------------------------
Initial Buffer:                 	[  -1v^  -1  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   1, Value   6	[   6v  -1^  -1  -1  -1  -1  -1  -1  -1  -1]
Consumer  4: Total   1, Value   6	[  -1  -1v^  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total   2, Value   6	[  -1   6v  -1^  -1  -1  -1  -1  -1  -1  -1]
Consumer  6: Total   2, Value   6	[  -1  -1  -1v^  -1  -1  -1  -1  -1  -1  -1]
Producer  1: Total   3, Value   5	[  -1  -1   5v  -1^  -1  -1  -1  -1  -1  -1]
Consumer  4: Total   3, Value   5	[  -1  -1  -1  -1v^  -1  -1  -1  -1  -1  -1]
Producer  2: Total   4, Value   5	[  -1  -1  -1   5v  -1^  -1  -1  -1  -1  -1]
Consumer  5: Total   4, Value   5	[  -1  -1  -1  -1  -1v^  -1  -1  -1  -1  -1]
Producer  2: Total   5, Value   2	[  -1  -1  -1  -1   2v  -1^  -1  -1  -1  -1]
Consumer  9: Total   5, Value   2	[  -1  -1  -1  -1  -1  -1v^  -1  -1  -1  -1]
Producer  0: Total   6, Value   1	[  -1  -1  -1  -1  -1   1v  -1^  -1  -1  -1]
Consumer  2: Total   6, Value   1	[  -1  -1  -1  -1  -1  -1  -1v^  -1  -1  -1]
Producer  2: Total   7, Value   5	[  -1  -1  -1  -1  -1  -1   5v  -1^  -1  -1]
Consumer  7: Total   7, Value   5	[  -1  -1  -1  -1  -1  -1  -1  -1v^  -1  -1]
Producer  2: Total   8, Value   7	[  -1  -1  -1  -1  -1  -1  -1   7v  -1^  -1]
Consumer  3: Total   8, Value   7	[  -1  -1  -1  -1  -1  -1  -1  -1  -1v^  -1]
Producer  2: Total   9, Value   1	[  -1  -1  -1  -1  -1  -1  -1  -1   1v  -1^]
Consumer  1: Total   9, Value   1	[  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1v^]
Producer  2: Total  10, Value   3	[  -1^  -1  -1  -1  -1  -1  -1  -1  -1   3v]
Consumer  0: Total  10, Value   3	[  -1v^  -1  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  1: Total  11, Value   9	[   9v  -1^  -1  -1  -1  -1  -1  -1  -1  -1]
Consumer  8: Total  11, Value   9	[  -1  -1v^  -1  -1  -1  -1  -1  -1  -1  -1]
Producer  2: Total  12, Value   4	[  -1   4v  -1^  -1  -1  -1  -1  -1  -1  -1]
Consumer  6: Total  12, Value   4	[  -1  -1  -1v^  -1  -1  -1  -1  -1  -1  -1]
Producer  0: Total  13, Value   2	[  -1  -1   2v  -1^  -1  -1  -1  -1  -1  -1]
Consumer  4: Total  13, Value   2	[  -1  -1  -1  -1v^  -1  -1  -1  -1  -1  -1]
Producer  1: Total  14, Value   4	[  -1  -1  -1   4v  -1^  -1  -1  -1  -1  -1]
Consumer  9: Total  14, Value   4	[  -1  -1  -1  -1  -1v^  -1  -1  -1  -1  -1]
Producer  1: Total  15, Value   2	[  -1  -1  -1  -1   2v  -1^  -1  -1  -1  -1]
Consumer  5: Total  15, Value   2	[  -1  -1  -1  -1  -1  -1v^  -1  -1  -1  -1]
Producer  2: Total  16, Value   3	[  -1  -1  -1  -1  -1   3v  -1^  -1  -1  -1]
Consumer  3: Total  16, Value   3	[  -1  -1  -1  -1  -1  -1  -1v^  -1  -1  -1]
Producer  0: Total  17, Value   0	[  -1  -1  -1  -1  -1  -1   0v  -1^  -1  -1]
Consumer  1: Total  17, Value   0	[  -1  -1  -1  -1  -1  -1  -1  -1v^  -1  -1]
Producer  2: Total  18, Value   4	[  -1  -1  -1  -1  -1  -1  -1   4v  -1^  -1]
Consumer  2: Total  18, Value   4	[  -1  -1  -1  -1  -1  -1  -1  -1  -1v^  -1]
-----------+---------
Produced   |   18
Consumed   |   18
-----------+---------

```
---
## How to test:



---

## Known bugs & limitations:

The value to be inserted into the buffer within the range of 0-9

If an item is removed, then it will write a -1 to mark it

If you find any bugs, please report to [li.sanh@uwlax.edu](mailto:li.sanh@uwlax.edu) or [zhang.huif@uwlax.edu](mailto:zhang.huif@uwlax.edu)



