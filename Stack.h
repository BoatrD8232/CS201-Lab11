#pragma once
#include "LinkedList.h"

class Stack : public LinkedList {
	private:
	public:
		// Adds a node to front of the singly linked list.
		void addNode(Data d);
		// Removes a node from the front of the singly linked list.
		Data delNode();
		// Returns the number of node in the list.
		int getNumItems();
};
