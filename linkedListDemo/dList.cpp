#include "dList.h"

dNode* dList::init(int data)
{
	dNode* newNode = new dNode();
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

int dList::addNodeFront(dNode** list, int data)
{
	if (*list == NULL)
	{
		return 1;
	}

	dNode* head = *list;
	dNode* newHead = new dNode();
	newHead->data = data;
	newHead->next = head;
	newHead->prev = NULL;
	head->prev = newHead;
	*list = newHead;
	return 0;
}

int dList::addNodeBack(dNode* list, int data)
{
	if (list == NULL)
	{
		return 1;
	}

	do {
		if (list->next == NULL)
		{
			dNode* newNode = new dNode();
			newNode->data = data;
			newNode->next = NULL;
			newNode->prev = list;
			list->next = newNode;
			return 0;
		}
		list = list->next;
	} while (list != NULL);
}

int dList::returnPtrByPos(dNode* list, int pos, dNode* &ptr)
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

int dList::returnPosByPtr(dNode* list, int &pos, dNode* ptr)
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

int dList::returnDataByPos(dNode* list, int &data, int pos)
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
	} while (list != NULL);
	return -1;
}

int dList::updateDataByPos(dNode* list, int data, int pos)
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

int dList::findDataReturnPos(dNode* list, int data, int &pos)
{
	if (list == NULL)
	{
		return 1;
	}

	int tempPos = 0;
	do {
		if (list->data == data)
		{
			pos == tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
	return -1;
}

int dList::findDataReturnPtr(dNode* list, int data, dNode* &ptr)
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

int dList::clear(dNode** list)
{
	if (*list == NULL)
	{
		return 1;
	}

	do {
		dNode* dummy = *list;
		*list = dummy->next;
		delete dummy;
	} while (*list != NULL);
	return 0;
}

int dList::size(dNode* list, int &nodeCount)
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

int dList::isEmpty(dNode* list)
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

int dList::print(dNode* list)
{
	if (list == NULL)
	{
		return 1;
	}

	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << list->prev << '\n';
		++tempPos;
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
	return 0;
}