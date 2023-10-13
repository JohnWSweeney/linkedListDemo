#include "sList.h"
// sweeney's hand-rolled singly linked list.
//
// error codes:
// 0	no error.
// 1	list is nullptr.
// 2	ptr is nullptr.
// -1	pos/ptr not in list.


node* sList::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	return newNode;
}

int sList::addNodeFront(node* list, int data)
{
	if (list == nullptr) return 1;

	node* newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
	return 0;
}

int sList::addNodeBack(node* list, int data)
{
	if (list == nullptr) return 1;

	do {
		if (list->next == nullptr)
		{
			node* newNode = new node();
			newNode->data = data;
			newNode->next = nullptr;
			list->next = newNode;
			return 0;
		}
		list = list->next;
	} while (list != nullptr);
}

int sList::addNodeByPos(node* list, int data, int pos)
{
	if (list == nullptr) return 1;

	if (pos == 0) // if adding node to front.
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
		int tempPos = 1;
		do {
			if (pos == tempPos)
			{
				node* after = list->next;
				node* newNode = new node();
				newNode->data = data;
				newNode->next = after;
				list->next = newNode;
				return 0;
			}
			++tempPos;
			list = list->next;
		} while (list->next != nullptr);
		return -1;
	}
}

int sList::deleteNodeFront(node** list)
{
	if (*list == nullptr) return 1;

	node* dummy = *list;
	*list = dummy->next;
	delete dummy;
	return 0;
}

int sList::deleteNodeBack(node** list)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	do {
		node* dummy = *list;
		if (dummy->next == nullptr) // check if list has only one node.
		{
			delete dummy;
			*list = nullptr;
			return 0;
		}
		else if (dummy->next->next == nullptr)
		{
			delete dummy->next;
			dummy->next = nullptr;
			*list = head;
			return 0;
		}
		*list = dummy->next;
	} while (*list != nullptr);
}

int sList::deleteNodeByPos(node** list, int pos)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	if (pos == 0)
	{
		node* newHead = head->next;
		delete head;
		*list = newHead;
		return 0;
	}

	int tempPos = 1;
	do {
		node* curr = *list;
		if (tempPos == pos)
		{
			node* dummy = curr->next;
			curr->next = curr->next->next;
			delete dummy;
			*list = head;
			return 0;
		}
		++tempPos;
		*list = curr->next;
	} while (*list != nullptr);
	return -1;
}

int sList::deleteNodeByPtr(node** list, node* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

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
		} while (curr != nullptr);
		return -1;
	}
}

int sList::deleteBeforePos(node** list, int pos)
{
	if (*list == nullptr) return 1;
	if (pos == 0) return 0;

	node* head = *list;
	if (head->next != nullptr)
	{
		*list = head->next;
	}
	// first, verify the position is in the list.
	int tempPos = 1;
	do {
		node* curr = *list;
		if (tempPos == pos) // position found.
		{
			// reset list and delete nodes up to pos.
			tempPos = 0;
			*list = head;
			do {
				node* dummy = *list;
				*list = dummy->next;
				delete dummy;
				++tempPos;
			} while (tempPos != pos);
			head = curr;
			*list = head;
			return 0;
		}
		++tempPos;
		*list = curr->next;
	} while (*list != nullptr);
	*list = head;
	return -1;
}

int sList::deleteBeforePtr(node** list, node* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = *list;
	if (ptr == head) return 0;
	// first, verify ptr is in list.
	do {
		node* curr = *list;
		if (curr == ptr) // found ptr.
		{
			// reset list and delete nodes before ptr.
			*list = head;
			do {
				node* dummy = *list;
				*list = dummy->next;
				delete dummy;
			} while (*list != ptr);
			head = curr;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != nullptr);
	*list = head;
	return -1;
}

int sList::deleteAfterPos(node** list, int pos)
{
	if (*list == nullptr) return 1;

	node* head = *list;

	int tempPos = 0;
	do {
		node* curr = *list;
		if (tempPos == pos)
		{
			// if pos is tail node or list has only one node.
			if (curr->next == nullptr)
			{
				*list = head;
				return 0;
			}
			// detach list after pos.
			node* temp = curr->next;
			curr->next = nullptr;

			// delete detached portion of list.
			do {
				node* dummy = temp;
				temp = temp->next;
				delete dummy;
			} while (temp != nullptr);

			*list = head;
			return 0;
		}
		++tempPos;
		*list = curr->next;
	} while (*list != nullptr);
	return -1;
}

int sList::deleteAfterPtr(node** list, node* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = *list;
	do {
		node* curr = *list;
		if (curr == ptr)
		{
			// if pos is tail node or list has only one node.
			if (curr->next == nullptr)
			{
				*list = head;
				return 0;
			}
			// detach list after pos.
			node* temp = curr->next;
			curr->next = nullptr;
			// delete detached portion of list.
			do {
				node* dummy = temp;
				temp = temp->next;
				delete dummy;
			} while (temp != nullptr);

			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != nullptr);
	*list = head;
	return -1;
}

int sList::returnPtrByPos(node* list, int pos, node* &ptr)
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

int sList::returnPosByPtr(node* list, int &pos, node* ptr)
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

int sList::returnDataByPos(node* list, int &data, int pos)
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
	} while (list != 0);
	return -1;
}

int sList::returnDataByPtr(node* list, int &data, node* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	do {
		if (list == ptr)
		{
			data = list->data;
			return 0;
		}
		list = list->next;
	} while (list != nullptr);
	return -1;
}

int sList::updateDataByPos(node* list, int data, int pos)
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

int sList::updateDataByPtr(node* list, int data, node* ptr)
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

int sList::findDataReturnPos(node* list, int data, int &pos)
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

int sList::findDataReturnPtr(node* list, int data, node* &ptr)
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

int sList::findMinReturnPos(node* list, int &min, int &pos)
{
	if (list == nullptr) return 1;

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
	} while (list != nullptr);
	return 0;
}

int sList::findMinReturnPtr(node* list, int &min, node* &ptr)
{
	if (list == nullptr) return 1;

	min = list->data;
	ptr = list;
	do {
		if (list->data < min)
		{
			min = list->data;
			ptr = list;
		}
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int sList::findMaxReturnPos(node* list, int &max, int &pos)
{
	if (list == nullptr) return 1;

	max = list->data;
	pos = 0;
	list = list->next;
	int tempPos = 1;
	do {
		if (list->data > max)
		{
			max = list->data;
			pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int sList::findMaxReturnPtr(node* list, int &max, node* &ptr)
{
	if (list == nullptr) return 1;

	max = list->data;
	ptr = list;
	do {
		if (list->data > max)
		{
			max = list->data;
			ptr = list;
		}
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int sList::findTailReturnPos(node* list, int &pos)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	do {
		if (list->next == nullptr)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != nullptr);
}

int sList::findTailReturnPtr(node* list, node* &ptr)
{
	if (list == nullptr) return 1;

	do {
		if (list->next == nullptr)
		{
			ptr = list;
			return 0;
		}
		list = list->next;
	} while (list != nullptr);
}

int sList::movePosToFront(node** list, int pos)
{
	if (*list == nullptr) return 1;

	if (pos == 0) return 0;

	node* head = *list;
	int tempPos = 1;
	do {
		node* dummy = *list;
		if (tempPos == pos)
		{
			node* newHead = dummy->next;
			dummy->next = newHead->next;
			newHead->next = head;
			*list = newHead;
			return 0;
		}
		++tempPos;
		*list = dummy->next;
	} while (*list != nullptr);
	*list = head;
	return -1;
}

int sList::movePosToBack(node** list, int pos)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	bool foundPos = false;
	node* curr = nullptr;
	node* prev = nullptr;
	node* temp = nullptr;
	node* tail = nullptr;
	int tempPos = 0;
	do {
		curr = *list;
		// if desired node is head.
		if (tempPos == pos and pos == 0)
		{
			if (curr->next == nullptr) // if list has only one node.
			{
				return 0;
			}
			foundPos = true;
			temp = head;
			head = head->next;
		}
		// if desired node is between head and tail.
		else if (tempPos == pos and curr->next != nullptr)
		{
			foundPos = true;
			temp = curr;
			prev->next = curr->next;
		}
		// if desired node is tail.
		else if (tempPos == pos and curr->next == nullptr)
		{
			*list = head;
			return 0;
		}
		// find tail node.
		if (curr->next == nullptr)
		{
			tail = curr;
		}
		++tempPos;
		prev = curr;
		*list = curr->next;
	} while (*list != nullptr);
	*list = head;
	if (foundPos == true)
	{
		tail->next = temp;
		temp->next = nullptr;
		return 0;
	}
	else return -1;
}

int sList::movePtrToFront(node** list, node* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = *list;
	if (ptr == head) return 0;

	do {
		node* dummy = *list;
		if (dummy->next == ptr)
		{
			dummy->next = dummy->next->next;
			ptr->next = head;
			head = ptr;
			*list = head;
			return 0;
		}
		*list = dummy->next;
	} while (list != nullptr);
	return -1;
}

int sList::movePtrToBack(node** list, node* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = *list;
	node* curr = nullptr;
	bool foundPtr = false;
	do {
		curr = *list;
		// if desired node is head.
		if (head == ptr)
		{
			if (head->next == nullptr) // if list has only one node.
			{
				return 0;
			}
			foundPtr = true;
			head = ptr->next;
		}
		else if (curr->next == ptr)
		{
			foundPtr = true;
			curr->next = ptr->next;
		}
		*list = curr->next;
	} while (curr->next != nullptr);

	if (foundPtr == true)
	{
		curr->next = ptr;
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

int sList::clear(node** list)
{
	if (list == nullptr) return 1;

	do {
		node* dummy = *list;
		*list = dummy->next;
		delete dummy;
	} while (*list != nullptr);
	return 0;
}

int sList::isEmpty(node* list)
{
	if (list == nullptr) return 1;
	else return 0;
}

int sList::size(node* list, int &nodeCount)
{
	if (list == nullptr) return 1;

	nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int sList::print(node* list)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	std::cout << "#\tdata:\tlist:\t\t\tnext:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\t' << '\n';
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	std::cout << '\n';
	return 0;
}

int sList::reverse(node** list)
{
	if (*list == nullptr) return 1;

	node* tail = *list;
	if (tail->next == nullptr) // check if list has only one node.
	{
		return 0;
	}
	*list = tail->next;
	tail->next = nullptr;

	node* curr = nullptr;
	do {
		curr = *list;
		node* temp = curr->next;
		curr->next = tail;
		tail = curr;
		*list = temp;
	} while (*list != nullptr);
	*list = curr;
}

int sList::swap(node** list, node* ptr1, node* ptr2)
{
	if (*list == nullptr) return 1;
	if (ptr1 == nullptr) return 2;
	if (ptr2 == nullptr) return 3;
	if (ptr1 == ptr2) return 4;

	node* head = *list;

	node* prev = nullptr;
	bool foundPtr1 = false;
	bool foundPtr2 = false;
	node* temp1 = nullptr;
	node* temp2 = nullptr;
	do {
		node* curr = *list;
		if (curr == ptr1)
		{
			foundPtr1 = true;
			temp1 = prev;
		}
		if (curr == ptr2)
		{
			foundPtr2 = true;
			temp2 = prev;
		}
		prev = curr;
		*list = curr->next;
	} while (*list != nullptr);

	if (foundPtr1 == true and foundPtr2 == true)
	{
		node* dummy = nullptr;
		if (ptr1 == head)
		{
			head = ptr2;
			temp2->next = ptr1;
		}
		else if (ptr2 == head)
		{
			head = ptr1;
			temp1->next = ptr2;
		}
		else
		{
			dummy = temp1->next;
			temp1->next = temp2->next;
			temp2->next = dummy;
		}
		dummy = ptr1->next;;
		ptr1->next = ptr2->next;
		ptr2->next = dummy;
		*list = head;
		return 0;
	}
	if (foundPtr1 == false) return -1; // ptr1 not in list.
	if (foundPtr2 == false) return -2; // ptr2 not in list.
}

int sList::bubbleSort(node** list, bool isAscending)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	if (head->next == nullptr) return 0;

	int swaps = 0;
	int swapCount = 0;
	int sweepCount = 0;
	node* before = nullptr;
	node* curr = nullptr;
	node* after = nullptr;
	// keep sweeping list until there are no more swaps.
	do {
		swaps = 0;
		// sweep list, reordering adjacent nodes according to isAscending.
		do {
			curr = *list;
			after = curr->next;
			if (after != nullptr)
			{
				// sort ascending.
				if (isAscending == true)
				{
					if (curr->data > after->data)
					{
						curr->next = after->next;
						after->next = curr;
						if (curr == head)
						{
							head = after;
						}
						else
						{
							before->next = after;
						}
						++swaps;
					}
				}
				// sort descending.
				else
				{
					if (curr->data < after->data)
					{
						curr->next = after->next;
						after->next = curr;
						if (curr == head)
						{
							head = after;
						}
						else
						{
							before->next = after;
						}
						++swaps;
					}
				}
			}
			before = curr;
			*list = curr->next;
		} while (*list != nullptr);
		*list = head;
		swapCount += swaps;
		++sweepCount;
	} while (swaps != 0);
	*list = head;
	std::cout << "swapCount: " << swapCount << '\n';
	std::cout << "sweepCount: " << sweepCount << '\n';
	return 0;
}