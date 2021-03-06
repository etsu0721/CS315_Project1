#pragma once
# include "node.h"
#include <iomanip>

class linkedList {

public:
	// constructs linked list abstract data type (ADT)
	linkedList() {
		front = NULL;
		rear = NULL;
		totCount = 0;
		queueLength = 0;
	}

	// checks if linked list in empty
	bool isEmpty() {
		if (front == NULL && rear == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	// constructs a new node and populates its data members
	node *makeNode(string clientType, int count) {
		node *newNode = new node;
		newNode->clientType = clientType;
		newNode->clientNum = count;
		return newNode;
	}

	// inserts node at front of linked list (phone clients are inserted at front)
	void frontInsert(float currentTime) {
		totCount += 1;
		queueLength += 1;
		node *newNode = makeNode("Caller", totCount);
		// case of empty linked list
		if (front == NULL && rear == NULL) {
			front = newNode;
			rear = newNode;
		}
		// case of nonempty linked list
		else {
			newNode->next = front;
			front = newNode;
		}
		printEvent(newNode->clientType, "Arrival", newNode->clientNum, queueLength, currentTime);
	}

	// inserts node at rear of linked list (door clients are inserted at rear)
	void rearInsert(float currentTime) {
		totCount += 1;
		queueLength += 1;
		node *newNode = makeNode("Walk-in", totCount);
		// case of empty linked list
		if (front == NULL && rear == NULL) {
			front = newNode;
			rear = newNode;	
		}
		// case of nonempty linked list
		else {
			rear->next = newNode; // node currently at rear points to newNode
			rear = newNode;
		}
		printEvent(newNode->clientType, "Arrival", newNode->clientNum, queueLength, currentTime);
	}

	// removes node at front of queue
	void frontRemove(float currentTime) {
		// case of empty linked list
		if (front == NULL && rear == NULL) {
			cout << "Nothing to remove from empty linked list at " << currentTime << endl;
			return;
		}
		// case of single node linked list
		else if (front->next == NULL) {
			queueLength -= 1;
			printEvent(front->clientType, "Serviced", front->clientNum, queueLength, currentTime);
			node *p = front;
			front = NULL;
			rear = NULL;
			delete p;
		}
		// case of linked list of two or more nodes
		else {
			queueLength -= 1;
			printEvent(front->clientType, "Serviced", front->clientNum, queueLength, currentTime);
			node *p = front;
			front = front->next;
			delete p;
		}
	}

	// displays information about queue and events that occur
        void printEvent(string clientType, string event, int clientNum, int queueLength, float currentTime) {
                 cout << left << setw(15) << clientType << setw(12) << event << setw(12) << currentTime
                        << setw(15) << clientNum << setw(15) << queueLength << endl;
        }

private:
	node *front;
	node *rear;
	int totCount;
	int queueLength;
};
