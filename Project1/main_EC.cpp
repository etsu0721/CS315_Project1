#include <iostream>
#include <cstdlib> // for random number generation
#include <limits> // for really large value (+/- infinity)
#include "linkedList_EC.h"
using namespace std;

// Extra credit version of main.cpp

const float MAX_TIME = 10.0; // length of simulation
const float q = 1.0;	// queries answered as slow as every q seconds
const float d = 2.0;	// walk-ins arrive as slow as every d seconds
const float p = 2.0;	// callers arrive as slow as every p seconds

// returns random number between 0 and num
float getRandom(float num) {
	return (num * ((float)rand()) / RAND_MAX);
}

// returns minimum value given three (float) parameters
float getMinimum(float float1, float float2, float float3) {
	if (float1 <= float2 && float1 <= float3)
		return float1;
	else if (float2 <= float1 && float2 <= float3)
		return float2;
	else
		return float3;
}

// updates currentTime variable (conditional on 'isOverTimeLimit()'
void updateCurrentTime(float & currentTime, float increment) {
	currentTime += increment;
}

// invokes 'updateCurrentTime()' if MAX_TIME is not exceeded
bool isOverTimeLimit(float & currentTime, float increment) {
	if (currentTime + increment > MAX_TIME) {
		cout << "Max time (" << MAX_TIME << ") reached\n";
		return true;
	}
	else {
		updateCurrentTime(currentTime, increment);
		return false;
	}
}

int main() {
	linkedList LList = linkedList();

	// commenting out the statement below will give pseudo-random (i.e. same "random") values
	// for each execution
	srand(time(0));

	float currentTime = 0.0;	// current time in simulation
	float rand_q;	// time until next query is answered (random float between 0 and q)
	float rand_d;	// time until next walk-in arrives (random float between 0 and d)
	float rand_p;	// time until next caller arrives (random float between 0 and p)

	// display column headers for output
	cout << left << setw(15) << "Client Type" << setw(12) << "Event"
		<< setw(12) << "Time" << setw(15) << "Client Num."
		<< setw(15) << "Queue Length" << setw(15) << "Num. Walk-ins"
		<< setw(15) << "Num. Callers" <<  endl;
	cout << "------------------------------------------------------------"
	        << "------------------------------------------------" << endl;
	rand_d = getRandom(d);
	rand_p = getRandom(p);
	// case where walk-in arrives before caller
	if (rand_d < rand_p) {
		if (isOverTimeLimit(currentTime, rand_d)) {
			system("pause");
			return 0;
		}
		LList.rearInsert(currentTime);
		rand_p -= rand_d; // adjust for elapsed time
		rand_d = getRandom(d);
	}
	// case where caller arrives before walk-in
	else {
		if (isOverTimeLimit(currentTime, rand_p)) {
			system("pause");
			return 0;
		}
		LList.frontInsert(currentTime);
		rand_d -= rand_p; // adjust for elapsed time
		rand_p = getRandom(p);
	}
	rand_q = getRandom(q);

	while (currentTime < MAX_TIME) {
		// case where queue is nonempty
		if (!(LList.isEmpty())) {
			// case where next event is query being answered
			if (getMinimum(rand_d, rand_p, rand_q) == rand_q) {
				if (isOverTimeLimit(currentTime, rand_q))
					break;
				LList.frontRemove(currentTime);
				rand_d -= rand_q;
				rand_p -= rand_q;
				rand_q = getRandom(q);
			}
			// case where next event is walk-in arriving
			else if (getMinimum(rand_d, rand_p, rand_q) == rand_d) {
				if (isOverTimeLimit(currentTime, rand_q))
					break;
				LList.rearInsert(currentTime);
				rand_p -= rand_d;
				rand_q -= rand_d;
				rand_d = getRandom(d);
			}
			// case where next event is caller arriving
			else {
				if (isOverTimeLimit(currentTime, rand_p))
					break;
				LList.frontInsert(currentTime);
				rand_d -= rand_p;
				rand_q -= rand_p;
				rand_p = getRandom(p);
			}
		}
		// case where queue has become empty (next event cannot be query answered)
		else {
			// case where next event is walk-in arriving 
			if (getMinimum(rand_d, rand_p, numeric_limits<float>::max()) == rand_d) {
				if (isOverTimeLimit(currentTime, rand_d))
					break;
				LList.rearInsert(currentTime);
				rand_p -= rand_d;
				rand_d = getRandom(d);
			}
			// case where next event is caller arriving
			else {
				if (isOverTimeLimit(currentTime, rand_p))
					break;
				LList.frontInsert(currentTime);
				rand_d -= rand_p;
				rand_p = getRandom(p);
			}
		}
	}
	system("pause");
	return 0;
}
