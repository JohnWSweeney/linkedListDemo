#include "csList.h"

node* csList::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = newNode;
	return newNode;
}

int csList::addNodeFront(node* list, int data)
{
	if (list == NULL)
	{
		std::cout << "addNodeFront: list is empty.\n";
		return 1;
	}

	node* newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
	return 0;
}

int csList::addNodeBack(node* list, int data)
{
	if (list == NULL)
	{
		std::cout << "addNodeBack: list is empty.\n";
		return 1;
	}

	node* head = list;
	do {
		if (list->next == head)
		{
			node* newNode = new node();
			newNode->data = data;
			newNode->next = head;
			list->next = newNode;
			return 0;
		}
		list = list->next;
	} while (list != head);
}

int csList::deleteNodeFront(node*& list)
{
	if (list == NULL)
	{
		std::cout << "deleteNodeFront: list is empty.\n";
		return 1;
	}

	node* head = list;
	node* newHead = list->next;
	do {
		if (list->next == head)
		{
			list->next = newHead;
			delete head;
			list = newHead;
			return 0;
		}
		list = list->next;
	} while (list != head);
}

int csList::deleteNodeBack(node* list)
{
	if (list == NULL)
	{
		std::cout << "deleteNodeBack: list is empty.\n";
		return 1;
	}

	node* head = list;
	do {
		node* dummy = list->next;
		if (dummy->next == head)
		{
			list->next = head;
			delete dummy;
			return 0;
		}
		list = list->next;
	} while (list != head);
}

int csList::deleteNodeByPtr(node* list, node* ptr)
{
	if (list == NULL)
	{
		std::cout << "deleteNodeByPtr: list is empty.\n";
		return -1;
	}
	else if (ptr == NULL)
	{
		std::cout << "returnPosByPtr: pointer is null.\n";
		return -2;
	}

	node* head = list;
	do {
		node* dummy = list->next;
		if (dummy == ptr)
		{
			list->next = dummy->next;
			delete dummy;
			return 0;
		}
		list = list->next;
	} while (list != head);
	std::cout << "Pointer is not in list.\n";
	return 1;
}

node* csList::returnPtrByPos(node* list, int pos)
{
	if (list == NULL)
	{
		std::cout << "returnPtrByPos: list is empty.\n";
		return NULL;
	}

	node* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			return list;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << "Requested postition is out of bounds.\n";
	return NULL;
}

int csList::returnPosByPtr(node* list, node* ptr)
{
	if (list == NULL)
	{
		std::cout << "returnPosByPtr: list is empty.\n";
		return -2;
	}
	else if (ptr == NULL)
	{
		std::cout << "returnPosByPtr: pointer is null.\n";
		return -3;
	}

	node* head = list;
	int tempPos = 0;
	do {
		if (list == ptr)
		{
			return tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << "Pointer is not in list.\n";
	return -1;
}

int csList::returnDataByPos(node* list, int pos)
{
	if (list == NULL)
	{
		std::cout << "returnDataByPos: list is empty.\n";
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
	std::cout << "returnDataByPos: query is out of bounds: ";
	return INT_MIN;
}

int csList::updateNodeByPos(node* list, int pos, int data)
{
	if (list == NULL)
	{
		std::cout << "updateNodeByPos: list is empty.\n";
		return -1;
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
	std::cout << "updateNodeByPos: query is out of bounds: ";
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