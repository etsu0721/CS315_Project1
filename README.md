Programming Assignment 1: The Secretary 
By Elijah Sutton for CS315 - Algorithms & Data Structures

WHAT DOES THE PROGRAM DO?
------------------------------
	My program simulates an office's secretary fielding clients', both walk-ins and callers, queries.
A caller is inserted at the front of the queue regardless of who is currently at the front, and a  walk-in
is inserted at the back of the queue.
	Arrival times for walk-ins and callers are determined by independent uniformly-distributed random numbers.
Length of query is independently determined in the same way.


HOW DO I RUN THE PROGRAM?
-----------------------------
	This is my first usage of a Makefile. Once inside the Project1 directory,
to run the program, type 'make run' (without the single quotes) and enter.


EXTRA CREDIT
----------------------------
(1)	Added to the event log is the number of walk-ins and callers, respectively, after each event occurs.
Once inside the Project1 directory, to run the extra credit version of the program,
type 'make run_EC' (without the single quotes) and press enter.
