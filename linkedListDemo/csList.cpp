#include "csList.h"
// sweeney's hand-rolled circular singly linked list.
//
// error codes:
// 0	no error.
// 1	list is nullptr.
// 2	ptr is nullptr.
// -1	pos/ptr not in list.

node* csList::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = newNode;
	return newNode;
}

int csList::addNodeFront(node* list, int data)
{
	if (list == nullptr) return 1;

	node* newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
	return 0;
}

int csList::addNodeBack(node* list, int data)
{
	if (list == nullptr) return 1;

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

int csList::addNodeByPos(node* list, int data, int pos)
{
	if (list == nullptr) return 1;

	node* head = list;
	if (pos == 0)
	{
		node* newNode = new node();
		newNode->data = head->data;
		newNode->next = head->next;
		head->data = data;
		head->next = newNode;
		return 0;
	}

	node* prev = list;
	list = list->next;
	int tempPos = 1;
	do {
		if (tempPos == pos)
		{
			node* newNode = new node();
			newNode->data = data;
			newNode->next = list;
			prev->next = newNode;
			return 0;
		}
		++tempPos;
		prev = list;
		list = list->next;
	} while (list != head);
	return -1;
}

int csList::deleteNodeFront(node** list)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	if (head->next == head) // check if list has only one node.
	{
		delete head;
		*list = nullptr;
		return 0;
	}

	do {
		node* dummy = *list;
		if (dummy->next == head)
		{
			node* newHead = head->next;
			dummy->next = newHead;
			delete head;
			*list = newHead;
			return 0;
		}
		*list = dummy->next;
	} while (*list != head);
}

int csList::deleteNodeBack(node** list)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	if (head->next == head) // check if list has only one node.
	{
		delete head;
		*list = nullptr;
		return 0;
	}

	do {
		node* dummy = *list;
		if (dummy->next->next == head)
		{
			delete dummy->next;
			dummy->next = head;
			*list = head;
			return 0;
		}
		*list = dummy->next;
	} while (*list != head);
}

int csList::deleteNodeByPos(node** list, int pos)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	if (pos == 0) // delete node in first position.
	{
		if (head->next == head) // check if list has only one node.
		{
			delete head;
			*list = nullptr;
			return 0;
		}
		else
		{
			do {
				node* dummy = *list;
				if (dummy->next == head)
				{
					dummy->next = head->next;
					*list = head->next;
					delete head;
					return 0;
				}
				*list = dummy->next;
			} while (*list != head);
		}
	}
	else
	{
		int tempPos = 0;
		do {
			node* curr = *list;
			node* dummy = curr->next;
			if (tempPos == pos - 1)
			{
				curr->next = dummy->next;
				delete dummy;
				*list = head;
				return 0;
			}
			++tempPos;
			*list = curr->next;
		} while (*list != head);
		return -1;
	}
}

int csList::deleteNodeByPtr(node** list, node* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = *list;
	if (ptr == head) // delete node in first position.
	{
		if (head->next == head) // check if list has only one node.
		{
			delete head;
			*list = nullptr;
			return 0;
		}
		else
		{
			do {
				node* dummy = *list;
				if (dummy->next == head)
				{
					dummy->next = head->next;
					*list = head->next;
					delete head;
					return 0;
				}
				*list = dummy->next;
			} while (*list != head);
		}
	}
	else
	{
		do {
			node* curr = *list;
			node* dummy = curr->next;
			if (dummy == ptr)
			{
				curr->next = dummy->next;
				delete dummy;
				*list = head;
				return 0;
			}
			*list = dummy->next;
		} while (*list != head);
		return -1;
	}
}

int csList::deleteBeforePos(node** list, int pos)
{
	if (*list == nullptr) return 1;
	if (pos == 0) return 0; // invalid.
	node* head = *list;
	// pos == 0 is invalid, skip head.
	*list = head->next;
	node* prev = *list;
	int tempPos = 1;
	do {
		node* curr = *list;
		if (tempPos == pos)
		{
			// detach list before pos.
			prev->next = head;
			// delete detached list.
			node* temp = head;
			do {
				node* dummy = temp;
				temp = temp->next;
				delete dummy;
			} while (temp != head);
			// assign new head.
			node* newHead = curr;
			// find tail, connect to new head.
			do {
				curr = *list;
				if (curr->next == head) // found tail.
				{
					curr->next = newHead;
					*list = newHead;
					return 0;
				}
				*list = curr->next;
			} while (*list != head);
		}
		++tempPos;
		prev = curr;
		*list = curr->next;
	} while (*list != head);
	*list = head; // pos not in list, reset list.
	return -1;
}

int csList::deleteBeforePtr(node** list, node* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = *list;
	if (ptr == head) // invalid.
	{
		*list = head;
		return 0;
	}
	node* prev = *list; // store previous node in sweep.
	*list = head->next; // ptr == 0 is invalid, skip head.
	// find ptr in list.
	do {
		node* curr = *list;
		if (curr == ptr) // ptr found.
		{
			prev->next = nullptr; // detach list before ptr.
			// delete detached list.
			node* temp = head;
			do {
				node* dummy = temp;
				temp = temp->next;
				delete dummy;
			} while (temp != nullptr);
			node* newHead = curr; // assign new head node.
			// find tail node.
			do {
				curr = *list;
				if (curr->next == head)
				{
					// connect tail to new head.
					curr->next = newHead;
					*list = newHead;
					return 0;
				}
				*list = curr->next;
			} while (*list != head);
		}
		*list = curr->next;
	} while (*list != head);
	*list = head; // ptr not found in list, reset list.
	return -1;
}

int csList::deleteAfterPos(node** list, int pos)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	int tempPos = 0;
	do {
		node* curr = *list;
		if (tempPos == pos) // found pos in list.
		{
			// check if node is tail.
			if (curr->next == nullptr)
			{
				*list = head;
				return 0;
			}
			// else, detach list after pos.
			node* temp = curr->next;
			// connect new tail to head.
			curr->next = head;
			// delete detached list.
			do {
				node* dummy = temp;
				temp = temp->next;
				delete dummy;
			} while (temp != head);
			*list = head;
			return 0;
		}
		++tempPos;
		*list = curr->next;
	} while (*list != head);
	*list = head; // pos not in list, reset list.
	return -1;
}

int csList::deleteAfterPtr(node** list, node* ptr)
{
	if (*list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = *list;
	do {
		node* curr = *list;
		if (curr == ptr) // found ptr in list.
		{
			// check if ptr is tail.
			if (curr->next == nullptr)
			{
				*list = head;
				return 0;
			}
			// detach list after ptr.
			node* temp = curr->next;
			curr->next = head;
			// delete detached list.
			do {
				node* dummy = temp;
				temp = temp->next;
				delete dummy;
			} while (temp != head);
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
	*list = head; // ptr not in list, reset list.
	return -1;
}

int csList::returnPtrByPos(node* list, int pos, node* &ptr)
{
	if (list == nullptr) return 1;

	node* head = list;
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

int csList::returnPosByPtr(node* list, int &pos, node* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = list;
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

int csList::returnDataByPos(node* list, int &data, int pos)
{
	if (list == nullptr) return 1;

	node* head = list;
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

int csList::returnDataByPtr(node* list, int &data, node* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = list;
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

int csList::updateDataByPos(node* list, int pos, int data)
{
	if (list == nullptr) return 1;

	node* head = list;
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

int csList::updateDataByPtr(node* list, int data, node* ptr)
{
	if (list == nullptr) return 1;
	if (ptr == nullptr) return 2;

	node* head = list;
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

int csList::findDataReturnPos(node* list, int data, int &pos)
{
	if (list == nullptr) return 1;

	node* head = list;
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

int csList::findDataReturnPtr(node* list, int data, node* &ptr)
{
	if (list == nullptr) return 1;

	node* head = list;
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

int csList::findMinReturnPos(node* list, int &min, int &pos)
{
	if (list == nullptr) return 1;

	node* head = list;
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

int csList::findMinReturnPtr(node* list, int &min, node* &ptr)
{
	if (list == nullptr) return 1;

	node* head = list;
	min = head->data;
	ptr = head;
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

int csList::findMaxReturnPos(node* list, int &max, int &pos)
{
	if (list == nullptr) return 1;

	node* head = list;
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
	} while (list != head);
	return 0;
}

int csList::findMaxReturnPtr(node* list, int &max, node* &ptr)
{
	if (list == nullptr) return 1;

	node* head = list;
	max = head->data;
	ptr = head;
	list = list->next;
	do {
		if (list->data > max)
		{
			max = list->data;
			ptr = list;
		}
		list = list->next;
	} while (list != head);
	return 0;
}

int csList::findTailReturnPos(node* list, int &pos)
{
	if (list == nullptr) return 1;

	node* head = list;
	int tempPos = 0;
	do {
		if (list->next == head)
		{
			pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
}

int csList::findTailReturnPtr(node* list, node* &ptr)
{
	if (list == nullptr) return 1;

	node* head = list;
	do {
		if (list->next == head)
		{
			ptr = list;
			return 0;
		}
		list = list->next;
	} while (list != head);
}

int csList::clear(node** list)
{
	if (*list == nullptr) return 1;

	node* head = *list;
	do {
		node* dummy = *list;
		if (dummy->next == head)
		{
			delete dummy;
			*list = nullptr;
			return 0;
		}
		*list = dummy->next;
		delete dummy;
	} while (*list != nullptr);
	return 0;
}

int csList::size(node* list, int &nodeCount)
{
	if (list == nullptr) return 1;

	node* head = list;
	nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != head);
	return 0;
}

int csList::isEmpty(node* list)
{
	if (list == nullptr) return 1;
	else return 0;
}

int csList::print(node* list)
{
	if (list == nullptr) return 1;

	node* head = list;
	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\n';
		++tempPos;
		list = list->next;
	} while (list != head);
	std::cout << '\n';
	return 0;
}

int csList::reverse(node** list)
{
	if (*list == nullptr) return 1;

	node* tail = *list;
	node* head = tail;

	*list = head->next;
	do {
		node* curr = *list;
		node* temp = curr->next;
		curr->next = head;
		head = curr;
		tail->next = head;
		*list = temp;
	} while (*list != tail);
	*list = head;
	return 0;
}