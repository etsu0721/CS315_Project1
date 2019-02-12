#pragma once
#include <string>
#include <iostream>
using namespace std;

class node {
	friend class linkedList;

public:
	node() {
		clientNum = 0;
		clientType = "";
		next = NULL;
		queryTime = 0.0;
		//cout << "node allocated" << endl;
	} // constructs node

	void print() {
		cout << "Client type: " << clientType << "Client number: " << clientNum << endl;
	}

private:
	int clientNum;	// unique client identifier
	string clientType;		// door client or phone client
	node *next;		// pointer to next node (may be NULL)
	float queryTime;
};
