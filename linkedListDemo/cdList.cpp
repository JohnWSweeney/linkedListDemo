#include "cdList.h"
// sweeney's hand-rolled circular doubly linked list.

dNode* cdList::init(int data)
{
	dNode* newNode = new dNode();
	newNode->data = data;
	newNode->next = newNode;
	newNode->prev = newNode;
	return newNode;
}

int cdList::addNodeFront(dNode* list, int data)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	dNode* after = head->next;
	dNode* newNode = new dNode();
	newNode->data = head->data;
	newNode->next = after;
	newNode->prev = head;
	head->data = data;
	head->next = newNode;
	after->prev = newNode;
	return 0;
}

int cdList::addNodeBack(dNode* list, int data)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	do {
		if (list->next == head)
		{
			dNode* newNode = new dNode();
			newNode->data = data;
			newNode->next = head;
			newNode->prev = list;
			list->next = newNode;
			head->prev = newNode;
			return 0;
		}
		list = list->next;
	} while (list != head);
}

int cdList::size(dNode* list, int &nodeCount)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != head);
	return 0;
}

int cdList::print(dNode* list)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << list->prev << '\n';
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << '\n';
	return 0;
}