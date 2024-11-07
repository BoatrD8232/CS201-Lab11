#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Data {
	// The number stored in data.
	int operand;
	Data(int op = 0) : operand(op) {}
};

struct Node {
	// The number stored by the node.
	Data data;
	Node* nextPtr;
	Node(Data dataItem, Node* next_ptr = nullptr) :data(dataItem), nextPtr(next_ptr) {}
};

class LinkedList {
protected:
	Node* headPtr;
	Node* tailPtr;
	int numItems;
public:
	LinkedList();
	~LinkedList();
	void virtual addNode(Data d) = 0;
	Data virtual delNode() = 0;
	// Returns true if empty, false otherwise.
	bool isEmpty();
	// Print the current contents of the list on a single line.
	void printList();
	// Returns the value stored by the head node.
	int getHeadVal();
};

