#include "sList.h"
// sweeney's hand-rolled singly linked list.

void sList::addNode(sNode *list, int data, int pos)
{
	sNode *newNode = new sNode();
	newNode->data = data;

	int tempPos = 1;
	do {
		if (tempPos == pos)
		{		
			newNode->next = list->next;
			list->next = newNode;
			return;
		}
		list = list->next;
		++tempPos;
	} while (list != NULL);
}

void sList::addNodeFront(sNode *list, int data)
{
	sNode *newNode = new sNode();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
}

void sList::addNodeBack(sNode *list, int data)
{
	sNode *newNode = new sNode();
	newNode->data = data;

	do {
		if (list->next == NULL)
		{
			list->next = newNode;
			return;
		}
		list = list->next;
	} while (list != NULL);
}

int sList::accessNode(sNode *list, int pos)
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
	return INT_MIN;
}

int sList::updateNodeData(sNode *list, int data, int pos)
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

void sList::deleteNode(sNode *list, int pos)
{
	int tempPos = 0;
	do {
		if (tempPos == pos - 1)
		{
			sNode* dummy = list->next;
			list->next = dummy->next;
			delete dummy;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
}

int sList::size(sNode *list)
{
	int sNodeCount = 0;
	do {
		++sNodeCount;
		list = list->next;
	} while (list != NULL);
	return sNodeCount;
}

void sList::printList(sNode *list, bool showDetails)
{
	if (showDetails == true)
	{
		std::cout << "#:\tdata:\tlink:\n";
	}
	int tempPos = 0;
	do {
		if (showDetails == true)
		{
			std::cout << tempPos << '\t' << list->data << '\t' << list->next << '\n';
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

int sList::find(sNode *list, int data)
{
	int tempPos = 0;
	do {
		if (list->data == data)
		{
			return tempPos;
		}
		else
		{
			++tempPos;
			list = list->next;
		}
	} while (list != NULL);
	return -1;
}