#include "dList.h"
// sweeney's hand-rolled doubly linked list.
//
// error codes:
// 0	no error.
// 1	list is nullptr.
// 2	ptr is nullptr.
// -1	pos/ptr not in list.


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

int dList::addNodeByPos(dNode* list, int data, int pos)
{
	if (list == nullptr) return 1;

	dNode* head = list;
	if (pos == 0) // add node to front.
	{
		dNode* newNode = new dNode();
		newNode->data = head->data;
		newNode->prev = head;
		head->data = data;
		if (head->next == nullptr) // if the list has only one node.
		{
			newNode->next = nullptr;
		}
		else // if the list has more than one node.
		{
			dNode* after = head->next;
			newNode->next = after;
			after->prev = newNode;
		}
		head->next = newNode;
		return 0;
	}
	else // add node after the front node.
	{
		list = list->next;
		int tempPos = 1;
		do {
			if (tempPos == pos)
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
		} while (list != nullptr);
		return -1;
	}
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
	*list = head;
	return -1;
}

int dList::deleteNodeByPtr(dNode** list, dNode* &ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	do {
		dNode* dummy = *list;
		if (*list == ptr)
		{
			if (dummy->prev == nullptr and dummy->next == nullptr) // list has only one node.
			{
				*list = nullptr;
			}
			else if (dummy->prev == nullptr) // first node
			{
				dNode* newHead = dummy->next;
				newHead->prev = nullptr;
				*list = newHead;
			}
			else if (dummy->next == nullptr) // last node.
			{
				dummy->prev->next = nullptr;
				*list = head;
			}
			else // between first and last nodes.
			{
				dNode* before = dummy->prev;
				dNode* after = dummy->next;
				before->next = after;
				after->prev = before;
				*list = head;
			}
			delete dummy;
			ptr = nullptr;
			return 0;
		}
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
	if (ptr == nullptr) return 2;

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

int dList::returnDataByPtr(dNode* list, int &data, dNode* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	do {
		if (list = ptr)
		{
			data = list->data;
			return 0;
		}
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

int dList::updateDataByPtr(dNode* list, int data, dNode* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	do {
		if (list == ptr)
		{
			list->data = data;
			return 0;
		}
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

int dList::findMinReturnPos(dNode* list, int &min, int &pos)
{
	if (list == nullptr) return 1;

	min = list->data;
	pos = 0;
	list = list->next;

	int tempPos = 1;
	do {
		if (min > list->data)
		{
			min = list->data;
			pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int dList::findMinReturnPtr(dNode* list, int &min, dNode* &ptr)
{
	if (list == nullptr) return 1;

	min = list->data;
	ptr = list;
	list = list->next;

	do {
		if (min > list->data)
		{
			min = list->data;
			ptr = list;
		}
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int dList::findMaxReturnPos(dNode* list, int &max, int &pos)
{
	if (list == nullptr) return 1;

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
	} while (list != nullptr);
	return 0;
}

int dList::findMaxReturnPtr(dNode* list, int &max, dNode* &ptr)
{
	if (list == nullptr) return 1;

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
	} while (list != nullptr);
	return 0;
}

int dList::movePtrToFront(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	if (ptr == head) return 0;

	do {
		dNode* curr = *list;
		if (curr->next == ptr)
		{
			dNode* after = ptr->next;
			curr->next = after;
			if (after != nullptr)
			{
				after->prev = curr;
			}
			head->prev = ptr;
			ptr->next = head;
			ptr->prev = nullptr;
			*list = ptr;
			return 0;
		}
		*list = curr->next;
	} while (*list != nullptr);
	return -1;
}

int dList::movePtrToBack(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	bool foundPtr = false;
	dNode* curr = nullptr;
	dNode* tail = nullptr;
	do {
		curr = *list;
		// list has only one node or desired node is tail.
		if (curr == ptr and curr->next == nullptr)
		{
			*list = head;
			return 0;
		}
		// desired node is not tail.
		else if (curr == ptr and curr->next != nullptr)
		{
			foundPtr = true;
			dNode* after = curr->next;
			if (ptr == head) // if desired node is head.
			{
				head = after;
				after->prev = nullptr;
			}
			else
			{
				dNode* before = curr->prev;
				before->next = after;
				after->prev = before;
			}
		}
		// find tail node.
		if (curr->next == nullptr)
		{
			tail = curr;
		}
		*list = curr->next;
	} while (*list != nullptr);

	if (foundPtr == true)
	{
		tail->next = ptr;
		ptr->prev = tail;
		ptr->next = nullptr;
		*list = head;
		return 0;
	}
	else
	{
		*list = head;
		return -1;
	}
}

int dList::movePtrUp(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	if (ptr == head) return 0;

	dNode* before = nullptr;
	dNode* newPos = nullptr; // new ptr position.
	dNode* curr = nullptr; // current ptr position.
	dNode* after = nullptr;
	do {
		curr = *list;
		// if desired node is second in list.
		if (curr == ptr and curr->prev == head)
		{
			after = curr->next;
			curr->prev = nullptr;
			curr->next = head;
			head->prev = curr;
			if (after != nullptr) // if list more than two nodes.
			{
				after->prev = head;
			}
			head->next = after;
			head = curr;
			*list = head;
			return 0;
		}
		// if desired node is b/w head and tail.
		else if (curr == ptr and curr->next != nullptr)
		{
			before = curr->prev->prev;
			newPos = curr->prev;
			after = curr->next;
			before->next = curr;
			curr->prev = before;
			curr->next = newPos;
			newPos->prev = curr;
			newPos->next = after;
			after->prev = newPos;
			*list = head;
			return 0;
		}
		// if desired node is tail.
		else if (curr == ptr and curr->next == nullptr)
		{
			before = curr->prev->prev;
			newPos = curr->prev;
			before->next = curr;
			curr->prev = before;
			curr->next = newPos;
			newPos->prev = curr;
			newPos->next = nullptr;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != nullptr);
	return -1;
}

int dList::movePtrDown(dNode** list, dNode* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	dNode* head = *list;
	dNode* before = nullptr;
	dNode* newPos = nullptr; // new ptr position.
	dNode* curr = nullptr; // current ptr position.
	dNode* after = nullptr;
	bool foundPtr = false;
	do {
		dNode* curr = *list;
		if (curr == ptr)
		{
			// ptr is tail node or list has only one node.
			if (curr->next == nullptr)
			{
				*list = head;
				return 0;
			}
			// ptr is head node.
			else if (curr == head)
			{
				newPos = curr->next; // new head.
				after = curr->next->next;
				newPos->prev = nullptr;
				newPos->next = curr;
				curr->prev = newPos;
				curr->next = after;
				if (after != nullptr) // if list more than two nodes.
				{
					after->prev = curr;
				}
				head = newPos;
				*list = head;
				return 0;
			}
			// ptr is second to last node.
			else if (curr->next->next == nullptr)
			{
				before = curr->prev;
				newPos = curr->next;
				before->next = newPos;
				newPos->prev = before;
				newPos->next = curr;
				curr->prev = newPos;
				curr->next = nullptr;
				*list = head;
				return 0;
			}
			// ptr is between head and tail nodes.
			else
			{
				before = curr->prev;
				newPos = curr->next;
				after = curr->next->next;
				before->next = newPos;
				newPos->prev = before;
				newPos->next = curr;
				curr->prev = newPos;
				curr->next = after;
				after->prev = curr;
				*list = head;
				return 0;
			}

		}
		*list = curr->next;
	} while (*list != nullptr);
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

int dList::reverse(dNode** list)
{
	if (*list == nullptr) return 1;

	dNode* tail = *list;
	*list = tail->next;
	tail->next = nullptr;

	dNode* curr = nullptr;
	do {
		curr = *list;
		dNode* temp = curr->next;
		curr->next = tail;
		tail->prev = curr;
		tail = curr;
		*list = temp;
	} while (*list != nullptr);
	*list = curr;
	return 0;
}