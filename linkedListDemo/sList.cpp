#include "sList.h"
// sweeney's hand-rolled singly linked list.

node* sList::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	return newNode;
}

int sList::addNodeFront(node* list, int data)
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

int sList::addNodeBack(node* list, int data)
{
	if (list == NULL)
	{
		return 1;
	}

	do {
		if (list->next == NULL)
		{
			node* newNode = new node();
			newNode->data = data;
			newNode->next = NULL;
			list->next = newNode;
			return 0;
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

int sList::deleteNodeFront(node** list)
{
	if (*list == NULL)
	{
		return 1;
	}

	node* dummy = *list;
	*list = dummy->next;
	delete dummy;
	return 0;
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

int sList::returnPosByPtr(node* list, int &pos, node* ptr)
{
	if (list == NULL)
	{
		return 1;
	}
	if (ptr == NULL)
	{
		return -2;
	}

	int tempPos = 0;
	do {
		if (list == ptr)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return -1;
}

int sList::returnDataByPos(node* list, int &data, int pos)
{
	if (list == NULL)
	{
		return 1;
	}

	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			data = list->data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != 0);
	return -1;
}

int sList::returnDataByPtr(node* list, int &data, node* ptr)
{
	if (list == NULL) return 1;
	if (ptr == NULL) return -2;

	do {
		if (list == ptr)
		{
			data = list->data;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
	return -1;
}

int sList::updateDataByPos(node* list, int data, int pos)
{
	if (list == NULL)
	{
		return 1;
	}

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
	return -1;
}

int sList::updateDataByPtr(node* list, int data, node* ptr)
{
	if (list == NULL)
	{
		return 1;
	}
	if (ptr == NULL)
	{
		return -2;
	}

	do {
		if (list == ptr)
		{
			list->data = data;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
	return -1;
}

int sList::findDataReturnPos(node* list, int data, int &pos)
{
	if (list == NULL)
	{
		return 1;
	}

	int tempPos = 0;
	do {
		if (list->data == data)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return -1;
}

int sList::findDataReturnPtr(node* list, int data, node* &ptr)
{
	if (list == NULL)
	{
		return 1;
	}

	do {
		if (list->data == data)
		{
			ptr = list;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
	return -1;
}

int sList::clear(node** list)
{
	if (list == NULL)
	{
		return 1;
	}

	do {
		node* dummy = *list;
		*list = dummy->next;
		delete dummy;
	} while (*list != NULL);
	return 0;
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

int sList::size(node* list, int &nodeCount)
{
	if (list == NULL)
	{
		return 1;
	}

	nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != NULL);
	return 0;
}

int sList::print(node* list)
{
	if (list == NULL)
	{
		return 1;
	}

	int tempPos = 0;
	std::cout << "#\tdata:\tlist:\t\t\tnext:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << '\n';
		++tempPos;
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
	return 0;
}