# CS# CS441/541
## Project 2 Part 1 Documentation

**Author:**
*Sanhu Li, Huifeng Zhang*

## Summary

This software is the solution for Project 2.2.

It simulates the problem described below.

### Problem Summary
Three groups of people: Republicans, Democrats and Independents are going voting in a polling station. The station has some voting boothes.

Constraints: Republicans cannot vote together with Democrats.

## How to build

	make

## How to use

	$ ./voter [num_booth] [num_republican] [num_democrat] [num_independent]

All the four arguments can be omitted. `[num_booth]` default to be 10, `[num_republican]`, `[num_democrat]` and `[num_independent]` default to be 5

## Examples

	./vote

Running results:

```
Number of Voting Booths:  10
Number of Republican   :   5
Number of Democrat     :   5
Number of Independent  :   5
------------------------+--------------------------------------+--------------------------------
Republican     1        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Republican     2        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Republican     0        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Republican     3        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Republican     4        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Democrat       0        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Democrat       1        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Democrat       2        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Democrat       4        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Democrat       3        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Independent    0        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Independent    1        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Independent    2        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Independent    3        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
Independent    4        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Waiting for polling station to open...
------------------------+--------------------------------------+--------------------------------
Republican     1        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Republican     2        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Republican     0        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Republican     3        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Independent    0        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Democrat       3        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Independent    1        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Republican     4        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Democrat       1        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Independent    3        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Democrat       4        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Democrat       0        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Independent    2        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Independent    4        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Democrat       2        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Entering the polling station
Independent    4 in  0  |->  [I][.][.][.][.][.][.][.][.][.]  <-| Voting!
Independent    2 in  1  |->  [I][I][.][.][.][.][.][.][.][.]  <-| Voting!
Democrat       2 in  2  |->  [I][I][D][.][.][.][.][.][.][.]  <-| Voting!
Democrat       2        |->  [I][I][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
Republican     1 in  2  |->  [I][I][R][.][.][.][.][.][.][.]  <-| Voting!
Republican     1        |->  [I][I][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
Independent    2        |->  [I][.][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
Republican     4 in  1  |->  [I][R][.][.][.][.][.][.][.][.]  <-| Voting!
Independent    3 in  2  |->  [I][R][I][.][.][.][.][.][.][.]  <-| Voting!
Independent    0 in  3  |->  [I][R][I][I][.][.][.][.][.][.]  <-| Voting!
Independent    1 in  4  |->  [I][R][I][I][I][.][.][.][.][.]  <-| Voting!
Republican     4        |->  [I][.][I][I][I][.][.][.][.][.]  <-| Leaving the polling station
Democrat       3 in  1  |->  [I][D][I][I][I][.][.][.][.][.]  <-| Voting!
Democrat       4 in  5  |->  [I][D][I][I][I][D][.][.][.][.]  <-| Voting!
Democrat       1 in  6  |->  [I][D][I][I][I][D][D][.][.][.]  <-| Voting!
Independent    4        |->  [.][D][I][I][I][D][D][.][.][.]  <-| Leaving the polling station
Democrat       0 in  0  |->  [D][D][I][I][I][D][D][.][.][.]  <-| Voting!
Democrat       1        |->  [D][D][I][I][I][D][.][.][.][.]  <-| Leaving the polling station
Independent    1        |->  [D][D][I][I][.][D][.][.][.][.]  <-| Leaving the polling station
Democrat       4        |->  [D][D][I][I][.][.][.][.][.][.]  <-| Leaving the polling station
Democrat       0        |->  [.][D][I][I][.][.][.][.][.][.]  <-| Leaving the polling station
Independent    3        |->  [.][D][.][I][.][.][.][.][.][.]  <-| Leaving the polling station
Independent    0        |->  [.][D][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
Democrat       3        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
Republican     2 in  0  |->  [R][.][.][.][.][.][.][.][.][.]  <-| Voting!
Republican     0 in  1  |->  [R][R][.][.][.][.][.][.][.][.]  <-| Voting!
Republican     3 in  2  |->  [R][R][R][.][.][.][.][.][.][.]  <-| Voting!
Republican     3        |->  [R][R][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
Republican     0        |->  [R][.][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
Republican     2        |->  [.][.][.][.][.][.][.][.][.][.]  <-| Leaving the polling station
------------------------+--------------------------------------+--------------------------------
```

## Test


## Special Section
1. Discribe your solution to the problem
	- Main thread is used to create the three groups of people and initialize the buffer and other things.
	- There's a lock to lock the polling station at the beginning.
	- Every voter need to wait for the lock.
	- After all work done by main thread, it waits for 2 seconds and then release the lock.
	- Main thread waits for all children to finish voting then close the station.
	- For Independents, they do not have any restriction if they get the resource lock for the booths. They will register for a while, then enter the station, try to vote, then leave the station.
	- For Republicans, their is a procedure which is made to be mutex by a binary semaphore.
	- In the procedure, it will check whether the current state is only for Democrats. If there's any Democrat voting there, it will keep on waiting until all Democrats have left the booths. Then try to change the current state to Republicans. If the current state is republicans, it will go on to vote like an Independent.
	- For Democrats, there's a similar procedure doing similar things.

2. Describe how your solution meets the goals of this part of the project, namely:
	* How does your solution avoid deadlock?
		- everyone using the same thread function voter. So the overroll sequence of waiting and releasing semaphore is the same. For the special judge part of Republicans and Democrats, I use a mutex lock and make sure it will not cause a deadlock.
	* How does your solution prevent Republican and Democrat voters from waiting on a voting booth at the same time?
		- In the special procedures, they will have to check whether there's anyone in the booths from another party. Only if there's no one from the other party in the booths, they will continue to go. These procedures are protected by a mutex lock. So it's safe and reliable.
	* How is your solution “fair”? How are you defining “fairness” for this problem?
		- I try to make the fairness problem simple. So when there's no one in the booths or only the people in Independent group are in the booths, there's a check: if there were some Republicans in last period, this period will belongs to the Democrats and vice versa. This may cause a potential problem that all Republicans may vote before all Democrats or the other way. But this will probably happen when there are a lot of booths there. If the booths are enough, then no one will wait for quite long. When the booths are not enough, it's more likely to become "fair". In sum, I think it's an acceptable solution.
	* How does your solution prevent starvation? How are you defining “starvation” for this problem?
		- My definition for starvation is that everyone can vote finally. So if there's no deadlock, everyone will vote in the end. My solution to prevent starvation is to try to avoid deadlock.

## Known Bugs and Program Areas

Not found currently. Of course there're bugs, but I really don't know right now.

If you find any bug, please report to [li.sanh@uwlax.edu](mailto:li.sanh@uwlax.edu) or [zhang.huif@uwlax.edu](mailto:zhang.huif@uwlax.edu)