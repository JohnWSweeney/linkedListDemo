#include "dList.h"

dNode* dList::init(int data)
{
	dNode* newNode = new dNode();
	newNode->data = data;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	return newNode;
}

int dList::addNodeFront(dNode** list, int data)
{
	if (*list == nullptr) return 1;

	dNode* head = *list;
	dNode* newHead = new dNode();
	newHead->data = data;
	newHead->next = head;
	newHead->prev = nullptr;
	head->prev = newHead;
	*list = newHead;
	return 0;
}

int dList::addNodeBack(dNode* list, int data)
{
	if (list == nullptr) return 1;

	do {
		if (list->next == nullptr)
		{
			dNode* newNode = new dNode();
			newNode->data = data;
			newNode->next = nullptr;
			newNode->prev = list;
			list->next = newNode;
			return 0;
		}
		list = list->next;
	} while (list != nullptr);
}

int dList::deleteNodeFront(dNode** list)
{
	if (*list == nullptr) return 1;

	dNode* head = *list;
	// if the list contains only one node.
	if (head->next == nullptr)
	{
		delete head;
		*list = nullptr;
		return 0;
	}
	else
	{
		dNode* newHead = head->next;
		newHead->prev = nullptr;
		delete head;
		*list = newHead;
		return 0;
	}
}

int dList::deleteNodeBack(dNode** list)
{
	if (*list == nullptr) return 1;

	dNode* head = *list;
	// if the list contains only one node.
	if (head->next == nullptr)
	{
		delete head;
		*list = nullptr;
		return 0;
	}

	do {
		dNode* curr = *list;
		if (curr->next->next == nullptr)
		{
			delete curr->next;
			curr->next = nullptr;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (list != nullptr);
}

int dList::deleteNodeByPos(dNode** list, int pos)
{
	if (*list == nullptr) return 1;

	dNode* head = *list;
	if (pos == 0)
	{
		if (head->next == nullptr)
		{
			delete head;
			*list = nullptr;
			return 0;
		}
		else
		{
			dNode* newHead = head->next;
			newHead->prev = nullptr;
			delete head;
			*list = newHead;
			return 0;
		}
	}

	int tempPos = 0;
	do {
		dNode* dummy = *list;
		if (tempPos == pos)
		{
			if (dummy->next == nullptr)
			{
				dummy->prev->next = nullptr;
				delete dummy;
				*list = head;
				return 0;
			}
			else
			{
				dNode* before = dummy->prev;
				dNode* after = dummy->next;
				delete dummy;
				before->next = after;
				after->prev = before;
				*list = head;
				return 0;
			}
		}
		++tempPos;
		*list = dummy->next;
	} while (*list != nullptr);
	return -1;
}

int dList::returnPtrByPos(dNode* list, int pos, dNode* &ptr)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			ptr = list;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	return -1;
}

int dList::returnPosByPtr(dNode* list, int &pos, dNode* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return -2;

	int tempPos = 0;
	do {
		if (list == ptr)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	return -1;
}

int dList::returnDataByPos(dNode* list, int &data, int pos)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			data = list->data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	return -1;
}

int dList::updateDataByPos(dNode* list, int data, int pos)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	return -1;
}

int dList::findDataReturnPos(dNode* list, int data, int &pos)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	do {
		if (list->data == data)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	return -1;
}

int dList::findDataReturnPtr(dNode* list, int data, dNode* &ptr)
{
	if (list == nullptr) return 1;

	do {
		if (list->data == data)
		{
			ptr = list;
			return 0;
		}
		list = list->next;
	} while (list != nullptr);
	return -1;
}

int dList::clear(dNode** list)
{
	if (*list == nullptr) return 1;

	do {
		dNode* dummy = *list;
		*list = dummy->next;
		delete dummy;
	} while (*list != nullptr);
	return 0;
}

int dList::size(dNode* list, int &nodeCount)
{
	if (list == nullptr) return 1;

	nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int dList::isEmpty(dNode* list)
{
	if (list == nullptr) return 1;
	else return 0;
}

int dList::print(dNode* list)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << list->prev << '\n';
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	std::cout << '\n';
	return 0;
}