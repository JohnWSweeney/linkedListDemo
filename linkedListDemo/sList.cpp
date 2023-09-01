#include "sList.h"
// sweeney's hand-rolled singly linked list.

node* sList::initList(int data)
{
	node* newNode = new node();
	newNode->data = data;
	return newNode;
}

void sList::addNode(node *list, int data, int pos)
{
	node *newNode = new node();
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

void sList::addNodeFront(node *list, int data)
{
	node *newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
}

void sList::addNodeBack(node *list, int data)
{
	node *newNode = new node();
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

int sList::accessNode(node *list, int pos)
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

int sList::updateNodeData(node *list, int data, int pos)
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

void sList::deleteNode(node *list, int pos)
{
	int tempPos = 0;
	do {
		if (tempPos == pos - 1)
		{
			node* dummy = list->next;
			list->next = dummy->next;
			delete dummy;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
}

void sList::deleteAfter(node* list, int pos)
{
	int tempPos = 0;
	do {
		++tempPos;
		list = list->next;
	} while (tempPos != pos);

	do {
		node* dummy = list->next;
		list->next = dummy->next;
		delete dummy;
	} while (list->next != NULL);
}

void sList::deleteNodeFront(node** list)
{
	node* dummy = *list;
	*list = dummy->next;
	delete dummy;
}

void sList::clear(node** list)
{
	if (list == NULL)
	{
		std::cout << "list is empty.\n";
		return;
	}

	do {
		node* dummy = *list;
		*list = dummy->next;
		delete dummy;
	} while (*list != NULL);
}

int sList::empty(node* list)
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

int sList::size(node *list)
{
	if (list == NULL)
	{
		std::cout << "list is empty.\n";
		return INT_MIN;
	}

	int nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != NULL);
	return nodeCount;
}

void sList::printList(node *list, bool showDetails)
{
	if (list == NULL)
	{
		std::cout << "list is empty.\n";
		return;
	}

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

int sList::find(node *list, int data)
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