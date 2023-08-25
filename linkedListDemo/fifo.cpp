#include "fifo.h"

void fifo::write(node* list, int data)
{
	node* newNode = new node();
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

int fifo::read(node*& list)
{
	node* dummy = list;
	int data = dummy->data;
	list = list->next;
	delete dummy;
	return data;
}

int fifo::size(node* list)
{
	int count = 0;
	do {
		++count;
		list = list->next;
	} while (list != NULL);
	return count;
}

void fifo::clear(node* list)
{
	if (list == NULL)
	{
		return;
	}

	do {
		node* dummy = list->next;
		list->next = dummy->next;
		delete dummy;
	} while (list->next != NULL);
	list->data = 0;
}

void fifo::print(node* list)
{
	int tempPos = 0;
	std::cout << "#\tdata:\tnext:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list->next << '\n';
		++tempPos;
		list = list->next;
	} while (list != NULL);
}