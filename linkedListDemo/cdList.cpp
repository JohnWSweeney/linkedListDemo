#include "cdList.h"
// sweeney's hand-rolled circular doubly linked list.

dNode* cdList::init(int data)
{
	dNode* head = new dNode();
	head->data = data;
	head->next = head;
	head->prev = head;
	return head;
}

void cdList::addNodeBack(dNode* list, int data)
{
	dNode* tail = list->prev;
	dNode* newNode = new dNode();
	newNode->data = data;
	newNode->next = list;
	newNode->prev = tail;
	list->prev = newNode;
	tail->next = newNode;
}

void cdList::deleteNodeBack(dNode*list)
{
	if (list == NULL)
	{
		std::cout << "List is empty.\n";
		return;
	}

	dNode* dummy = list->prev;
	dNode* newTail = dummy->prev;
	list->prev = newTail;
	newTail->next = list;
	delete dummy;
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
		std::cout << "List is empty.\n";
		return;
	}

	dNode* tail = list->prev;
	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	do {
		dNode* curr = list;
		std::cout << tempPos << '\t' << list->data << '\t' << curr << '\t' << list->next << '\t' << list->prev << '\n';
		++tempPos;
		list = list->next;
	} while (list->prev != tail);
	std::cout << '\n';
}