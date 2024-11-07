#include "LinkedList.h"

LinkedList::LinkedList() {
	headPtr = nullptr;
	tailPtr = nullptr;
	numItems = 0;
}
LinkedList::~LinkedList() {
	if (headPtr != nullptr) {
		while (headPtr != nullptr) {
			Node* nextNode = headPtr->nextPtr;
			delete headPtr;
			headPtr = nextNode;
		}
	}
}
bool LinkedList::isEmpty() {
	if (headPtr == nullptr) {
		return true;
	}
	return false;
}
void LinkedList::printList() {
	Node* currNode = headPtr;
	while (currNode != nullptr) {
		cout << currNode->data.operand << " " << endl;
		currNode = currNode->nextPtr;
	}
}
int LinkedList::getHeadVal() {
	return headPtr->data.operand;
}