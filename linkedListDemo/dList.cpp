#include "dList.h"

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

void dList::addNodeFront(dNode *list, int data)
{
	dNode *newNode = new dNode();
	newNode->data = list->data;
	newNode->next = list->next;
	newNode->prev = list;
	list->data = data;
	list->next = newNode;
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

void dList::printList(dNode *list)
{
	do {
		std::cout << list->data << '\n';
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
}