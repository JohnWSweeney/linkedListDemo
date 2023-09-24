#include "fifo.h"
// sweeney's hand-rolled first-in-first-out (FIFO) class.

node* fifo::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	return newNode;
}

void fifo::write(node* list, int data)
{
	if (list == NULL)
	{
		std::cout << "fifo.write: list is empty.\n";
		return;
	}

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
	if (list == NULL)
	{
		std::cout << "fifo.read: list is empty.\n";
		return INT_MIN;
	}

	node* dummy = list;
	int data = dummy->data;
	list = list->next;
	delete dummy;
	return data;
}

int fifo::size(node* list)
{
	if (list == NULL)
	{
		std::cout << "fifo.size: list is empty.\n";
		return INT_MIN;
	}

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
		std::cout << "fifo.clear: list is empty.\n";
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
	if (list == NULL)
	{
		std::cout << "fifo.print: list is empty.\n";
		return;
	}

	int tempPos = 0;
	std::cout << "#\tdata:\tnext:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list->next << '\n';
		++tempPos;
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
}