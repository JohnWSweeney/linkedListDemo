#include "sll.h"
// sweeney's hand-rolled singly linked list.

void sll::addNode(node *list, int data, int pos)
{
	node *newNode = new node();
	newNode->data = data;
	newNode->next = NULL;

	int tempPos = 1;
	node *prevNode;
	do {
		prevNode = list;
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

void sll::addNodeFront(node *list, int data)
{
	node *newNode = new node();
	
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
}

void sll::addNodeBack(node *list, int data)
{
	node *newNode = new node();
	newNode->data = data;
	newNode->next = NULL;

	do {
		if (list->next == NULL)
		{
			list->next = newNode;
			return;
		}
		list = list->next;
	} while (list != NULL);
}

int sll::accessNode(node *list, int pos)
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

void sll::updateNodeData(node *list, int data, int pos)
{
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
}

int sll::size(node *list)
{
	int nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != NULL);
	return nodeCount;
}

void sll::printList(node *list, bool showDetails)
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