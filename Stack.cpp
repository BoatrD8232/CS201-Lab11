#include "Stack.h"

void Stack::addNode(Data d) {
	headPtr = new Node(d, headPtr);
	numItems++;
}
Data Stack::delNode() {
	if (headPtr != nullptr) {
		Node* delNode = headPtr;
		Data temp = delNode->data;
		headPtr = headPtr->nextPtr;
		delete delNode;
		numItems--;
		return temp;
	}
	else {
		cout << "Cannot delete, stack is empty";
		return NULL;
	}
}
int Stack::getNumItems() {
	return numItems;
}