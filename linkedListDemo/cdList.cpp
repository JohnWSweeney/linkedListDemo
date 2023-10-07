#include "cdList.h"
// sweeney's hand-rolled circular doubly linked list.
//
// error codes:
// 0	no error.
// 1	list is nullptr.
// 2	ptr is nullptr.
// -1	pos/ptr not in list.

dNode* cdList::init(int data)
{
	dNode* newNode = new dNode();
	newNode->data = data;
	newNode->next = newNode;
	newNode->prev = newNode;
	return newNode;
}

int cdList::addNodeFront(dNode* list, int data)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	dNode* after = head->next;
	dNode* newNode = new dNode();
	newNode->data = head->data;
	newNode->next = after;
	newNode->prev = head;
	head->data = data;
	head->next = newNode;
	after->prev = newNode;
	return 0;
}

int cdList::addNodeBack(dNode* list, int data)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	do {
		if (list->next == head)
		{
			dNode* newNode = new dNode();
			newNode->data = data;
			newNode->next = head;
			newNode->prev = list;
			list->next = newNode;
			head->prev = newNode;
			return 0;
		}
		list = list->next;
	} while (list != head);
}

int cdList::addNodeByPos(dNode* list, int data, int pos)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos = 0;
	do {
		if (pos == 0)
		{
			dNode* after = head->next;
			dNode* newNode = new dNode();
			newNode->data = head->data;
			newNode->next = after;
			newNode->prev = head;
			head->data = data;
			head->next = newNode;
			after->prev = newNode;
			return 0;
		}
		else if (tempPos == pos)
		{
			dNode* before = list->prev;
			dNode* after = list;
			dNode* newNode = new dNode();
			newNode->data = data;
			newNode->next = after;
			newNode->prev = before;
			before->next = newNode;
			after->prev = newNode;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::deleteNodeFront(dNode** list)
{
	if (*list == nullptr) return 1;

	dNode* dummy = *list;
	if (dummy->next == dummy)
	{
		delete dummy;
		*list = nullptr;
		return 0;
	}
	else
	{
		dNode* newHead = dummy->next;
		dNode* tail = dummy->prev;
		newHead->prev = tail;
		tail->next = newHead;
		*list = newHead;
		return 0;
	}
}

int cdList::deleteNodeBack(dNode** list)
{
	if (*list == nullptr) return 1;

	dNode* head = *list;
	do {
		dNode* dummy = *list;
		// if the list contains only one node.
		if (dummy->next == head and dummy->prev == head)
		{
			delete dummy;
			*list = nullptr;
			return 0;
		}
		else if (dummy->next->next == head)
		{
			delete dummy->next;
			dummy->next = head;
			head->prev = dummy;
			*list = head;
			return 0;
		}
		*list = dummy->next;
	} while (*list != head);
}

int cdList::deleteNodeByPos(dNode** list, int pos)
{
	if (*list == nullptr) return 1;

	dNode* head = *list;
	int tempPos = 0;
	do {
		dNode* dummy = *list;
		// if the list contains only one node.
		if (dummy->next == dummy)
		{
			delete dummy;
			*list = nullptr;
			return 0;
		}
		else if (tempPos == pos)
		{
			dNode* before = dummy->prev;
			dNode* after = dummy->next;
			delete dummy;
			before->next = after;
			after->prev = before;
			if (pos == 0)
			{
				*list = after;
			}
			else
			{
				*list = head;
			}
			return 0;
		}
		++tempPos;
		*list = dummy->next;
	} while (*list != head);
	return -1;
}

int cdList::deleteNodeByPtr(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	do {
		dNode* dummy = *list;
		if (dummy == ptr)
		{
			dNode* before = dummy->prev;
			dNode* after = dummy->next;
			before->next = after;
			after->prev = before;
			if (dummy == head) // check if node to be deleted is head.
			{
				head = after;
			}
			delete dummy;
			*list = head;
			return 0;
		}
		*list = dummy->next;
	} while (*list != head);
	return -1;
}

int cdList::returnPtrByPos(dNode* list, int pos, dNode* &ptr)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			ptr = list;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::returnPosByPtr(dNode* list, int &pos, dNode* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = list;
	int tempPos = 0;
	do {
		if (list == ptr)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::returnDataByPos(dNode* list, int &data, int pos)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			data = list->data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::returnDataByPtr(dNode* list, int &data, dNode* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = list;
	do {
		if (list == ptr)
		{
			data = list->data;
			return 0;
		}
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::updateDataByPos(dNode* list, int data, int pos)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::updateDataByPtr(dNode* list, int data, dNode* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = list;
	do {
		if (list == ptr)
		{
			list->data = data;
			return 0;
		}
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::findDataReturnPos(dNode* list, int data, int &pos)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos = 0;
	do {
		if (list->data == data)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::findDataReturnPtr(dNode* list, int data, dNode* &ptr)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	do {
		if (list->data == data)
		{
			ptr = list;
			return 0;
		}
		list = list->next;
	} while (list != head);
	return -1;
}

int cdList::findMinReturnPos(dNode* list, int &min, int &pos)
{
	if (list == nullptr) return 1;

	dNode* head = list;

	min = list->data;
	pos = 0;
	list = list->next;

	int tempPos = 1;
	do {
		if (list->data < min)
		{
			min = list->data;
			pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return 0;
}

int cdList::findMinReturnPtr(dNode* list, int &min, dNode* &ptr)
{
	if (list == nullptr) return 1;

	dNode* head = list;

	min = list->data;
	ptr = list;
	list = list->next;
	do {
		if (list->data < min)
		{
			min = list->data;
			ptr = list;
		}
		list = list->next;
	} while (list != head);
	return 0;
}

int cdList::findMaxReturnPos(dNode* list, int &max, int &pos)
{
	if (list == nullptr) return 1;

	dNode* head = list;

	max = list->data;
	pos = 0;
	list = list->next;

	int tempPos = 1;
	do {
		if (max < list->data)
		{
			max = list->data;
			pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return 0;
}

int cdList::findMaxReturnPtr(dNode* list, int &max, dNode* &ptr)
{
	if (list == nullptr) return 1;

	dNode* head = list;

	max = list->data;
	ptr = list;
	list = list->next;
	do {
		if (max < list->data)
		{
			max = list->data;
			ptr = list;
		}
		list = list->next;
	} while (list != head);
	return 0;
}

int cdList::movePtrToFront(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	dNode* tail = head->prev;
	if (ptr == head) return 0;
	else if (ptr == tail)
	{
		head = tail;
		*list = head;
		return 0;
	}

	do {
		dNode* curr = *list;
		if (curr == ptr)
		{
			dNode* before = curr->prev;
			dNode* after = curr->next;
			before->next = after;
			after->prev = before;
			ptr->next = head;
			ptr->prev = tail;
			head->prev = ptr;
			tail->next = ptr;
			head = ptr;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
	return -1;
}

int cdList::movePtrToBack(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	dNode* tail = head->prev;
	if (ptr == head)
	{
		head = ptr->next;
		*list = head;
		return 0;
	}
	else if (ptr == tail) return 0;

	do {
		dNode* curr = *list;
		if (curr == ptr)
		{
			dNode* before = curr->prev;
			dNode* after = curr->next;
			before->next = after;
			after->prev = before;
			ptr->next = head;
			ptr->prev = tail;
			tail->next = ptr;
			head->prev = ptr;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
	return -1;
}

int cdList::movePtrUp(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	if (ptr == head) return 0;

	do {
		dNode* curr = *list;
		if (curr->next == ptr)
		{
			dNode* before = curr->prev;
			dNode* after = ptr->next;
			before->next = ptr;
			ptr->prev = before;
			ptr->next = curr;
			curr->prev = ptr;
			curr->next = after;
			after->prev = curr;
			if (curr == head)
			{
				*list = ptr;
			}
			else
			{
				*list = head;
			}
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
	return -1;
}

int cdList::movePtrDown(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	if (ptr == head->prev) return 0;

	dNode* curr = nullptr;
	do {
		curr = *list;
		if (curr == ptr)
		{
			dNode* before = curr->prev;
			dNode* newPos = curr->next;
			dNode* after = curr->next->next;
			before->next = newPos;
			newPos->prev = before;
			newPos->next = curr;
			curr->prev = newPos;
			curr->next = after;
			after->prev = curr;
			if (curr == head)
			{
				head = newPos;
			}
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
	return -1;
}

int cdList::clear(dNode** list)
{
	if (*list == nullptr) return 1;

	dNode* head = *list;
	do {
		dNode* dummy = *list;
		if (dummy->next != head)
		{
			*list = dummy->next;
			delete dummy;
		}
		else if (dummy->next == head)
		{
			delete dummy;
			*list = nullptr;
			return 0;
		}
	} while (*list != nullptr);
}

int cdList::isEmpty(dNode* list)
{
	if (list == nullptr) return 1;
	else return 0;
}

int cdList::size(dNode* list, int &nodeCount)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != head);
	return 0;
}

int cdList::print(dNode* list)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << list->prev << '\n';
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << '\n';
	return 0;
}

int cdList::printReverse(dNode* list)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	int tempPos;
	this->size(list, tempPos);
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\t\t\tprev:\n";
	do {
		list = list->prev;
		--tempPos;
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << list->prev << '\n';
	} while (list != head);
	std::cout << '\n';
	return 0;
}

int cdList::reverse(dNode** list)
{
	if (*list == nullptr) return 1;

	dNode* tail = *list;
	dNode* head = *list;
	*list = tail->next;

	dNode* curr = nullptr;
	do {
		curr = *list;
		dNode* temp = curr->next;
		curr->next = head;
		curr->prev = tail;
		head->prev = curr;
		tail->next = curr;
		head = curr;
		*list = temp;
	} while (*list != tail);
	*list = head;
	return 0;
}