#include "sList.h"
// sweeney's hand-rolled singly linked list.

node* sList::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	return newNode;
}

int sList::addNodeFront(node *list, int data)
{
	if (list == NULL)
	{
		return 1;
	}

	node* newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
	return 0;
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

int sList::addNodeByPos(node* list, int data, int pos)
{
	if (list == NULL)
	{
		return 1;
	}

	if (pos == 0)
	{
		node* newNode = new node();
		newNode->data = list->data;
		newNode->next = list->next;
		list->data = data;
		list->next = newNode;
		return 0;
	}
	else
	{
		int tempPos = 0;
		do {
			if (pos == tempPos + 1)
			{
				std::cout << list->data << '\n';
				node* after = list->next;
				node* newNode = new node();
				newNode->data = data;
				newNode->next = after;
				list->next = newNode;
				return 0;
			}
			++tempPos;
			list = list->next;
		} while (list->next != NULL);
		return -1;
	}
}

void sList::deleteNodeFront(node** list)
{
	node* dummy = *list;
	*list = dummy->next;
	delete dummy;
}

int sList::deleteNodeBack(node* list)
{
	if (list == NULL)
	{
		return 1;
	}

	do {
		node* dummy = list->next;
		if (dummy->next == NULL)
		{
			list->next = NULL;
			delete dummy;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
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

int sList::deleteNodeByPtr(node** list, node* ptr)
{
	if (list == NULL)
	{
		return 1;
	}
	if (ptr == NULL)
	{
		return -1;
	}

	if (*list == ptr)
	{
		node* dummy = *list;
		*list = dummy->next;
		delete dummy;
		return 0;
	}
	else
	{
		node* curr = *list;
		do {
			node* dummy = curr->next;
			if (dummy == ptr)
			{
				curr->next = dummy->next;
				delete dummy;
				return 0;
			}
			curr = curr->next;
		} while (curr != NULL);
		return -2;
	}
}

int sList::returnPtrByPos(node* list, int pos, node* &ptr)
{
	if (list == NULL)
	{
		return 1;
	}

	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			ptr = list;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return -1;
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

int sList::isEmpty(node* list)
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

void sList::print(node *list)
{
	if (list == NULL)
	{
		std::cout << "list is empty.\n";
		return;
	}

	std::cout << "#:\tdata:\tlist:\t\t\tnext:\n";
	int tempPos = 0;
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\n';
		++tempPos;
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
}