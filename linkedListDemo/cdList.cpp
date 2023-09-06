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
	if (list == NULL)
	{
		std::cout << "addNodeFront: list is empty.\n";
		return 1;
	}

	dNode* newNode = new dNode();
	newNode->data = list->data;
	newNode->next = list->next;
	newNode->prev = list;
	list->data = data;
	list->next = newNode;
	return 0;
}

int cdList::addNodeBack(dNode* list, int data)
{
	if (list == NULL)
	{
		std::cout << "addNodeBack: list is empty.\n";
		return 1;
	}

	dNode* tail = list->prev;
	dNode* newNode = new dNode();
	newNode->data = data;
	newNode->next = list;
	newNode->prev = tail;
	list->prev = newNode;
	tail->next = newNode;
	return 0;
}

int cdList::deleteNodeFront(dNode** list)
{
	if (list == NULL)
	{
		std::cout << "deleteNodeFront: list is empty.\n";
		return 1;
	}

	dNode* dummy = *list;
	dNode* before = dummy->prev;
	dNode* after = dummy->next;
	before->next = after;
	after->prev = before;
	delete dummy;
	*list = after;
	return 0;
}

int cdList::deleteNodeBack(dNode* list)
{
	if (list == NULL)
	{
		std::cout << "deleteNodeBack: list is empty.\n";
		return 1;
	}

	dNode* head = list;
	do {
		dNode* dummy = list->next;
		if (dummy->next == head)
		{
			list->next = head;
			head->prev = list;
			delete dummy;
			return 0;
		}
		list = list->next;
	} while (list != head);
	return 1;
}

dNode* cdList::returnPtrByPos(dNode* list, int pos)
{
	dNode* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			return list;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
}

int cdList::size(dNode* list)
{
	if (list == NULL)
	{
		std::cout << "cdList.size: list is empty.\n";
		return -1;
	}

	dNode* head = list;
	int nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != head);
	return nodeCount;
}

int cdList::isEmpty(dNode* list)
{
	if (list == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void cdList::print(dNode* list)
{
	if (list == NULL)
	{
		std::cout << "cdList.print: list is empty.\n";
		return;
	}

	dNode* head = list;
	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << list->prev << '\n';
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << '\n';
}

void cdList::printReverse(dNode* list)
{
	if (list == NULL)
	{
		std::cout << "cdList.printReverse: list is empty.\n";
		return;
	}

	dNode* head = list;
	int tempPos = size(list) - 1;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	list = list->prev;
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << list->prev << '\n';
		--tempPos;
		list = list->prev;
	} while (list->next != head);
	std::cout << '\n';
}