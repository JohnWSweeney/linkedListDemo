#include "dList.h"

void dList::addNodeFront(dNode *list, int data)
{
	dNode *newNode = new dNode();
	newNode->data = list->data;
	newNode->next = list->next;
	newNode->prev = list;
	list->data = data;
	list->next = newNode;
}

void dList::addNodeBack(dNode *list, int data)
{
	dNode *newNode = new dNode();
	newNode->data = data;

	do {
		if (list->next == NULL)
		{
			list->next = newNode;
			newNode->prev = list;
			return;
		}
		list = list->next;
	} while (list != NULL);
}

int dList::accessNode(dNode *list, int pos)
{
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			return list->data;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
}

int dList::updateNodeData(dNode *list, int data, int pos)
{
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return 1;
}

void dList::deleteNode(dNode* list, int pos)
{
	int tempPos = 0;
	do {
		if (tempPos == pos - 1)
		{
			dNode* dummy = list->next;
			list->next = dummy->next;
			list = list->next;
			list->prev = dummy->prev;
			delete dummy;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
}

int dList::size(dNode *list)
{
	int nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != NULL);
	return nodeCount;
}

void dList::printList(dNode *list, bool showDetails)
{
	if (showDetails == true)
	{
		std::cout << "#:\tdata:\tprev:\t\t\tnext:\n";
	}
	int tempPos = 0;
	do {
		if (showDetails == true)
		{
			std::cout << tempPos << '\t' << list->data << '\t' << list->prev << '\t' << list->next << '\n';
		}
		else
		{
			std::cout << list->data << '\n';
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
}

int dList::find(dNode *list, int data)
{
	int tempPos = 0;
	do {
		if (list->data == data)
		{
			return tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return INT_MIN;
}