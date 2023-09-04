#include "csList.h"

node* csList::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = newNode;
	return newNode;
}

void csList::addNodeFront(node* list, int data)
{
	node* newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
}

void csList::addNodeBack(node* list, int data)
{
	node* newNode = new node();
	newNode->data = data;

	node* head = list;
	do {
		if (list->next == head)
		{
			list->next = newNode;
			newNode->next = head;
			return;
		}
		list = list->next;
	} while (list != head);
}

int csList::accessNode(node* list, int pos)
{
	if (list == NULL)
	{
		std::cout << "accessNode: list is empty.\n";
		return INT_MIN;
	}

	node* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			return list->data;
		}
		else if (tempPos > pos)
		{
			break;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << "accessNode: query is out of bounds: ";
}

int csList::updateNode(node* list, int pos, int data)
{
	if (list == NULL)
	{
		std::cout << "updateNode: list is empty.\n";
		return INT_MIN;
	}

	node* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
			return 0;
		}
		else if (tempPos > pos)
		{
			break;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << "updateNode: query is out of bounds: ";
	return 1;
}

int csList::size(node* list)
{
	if (list == NULL)
	{
		std::cout << "size: list is empty.\n";
		return -1;
	}

	node* head = list;
	int nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != head);
	return nodeCount;
}

int csList::isEmpty(node* list)
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

void csList::print(node* list)
{
	if (list == NULL)
	{
		std::cout << "print: list is empty.\n";
		return;
	}

	node* head = list;
	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\n';
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << '\n';
}