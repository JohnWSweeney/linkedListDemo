#include "fifo.h"
// sweeney's hand-rolled first-in-first-out (FIFO) class.

int fifo::wr_en(node* &list, int din)
{
	if (list == nullptr)
	{
		node* newNode = new node();
		newNode->data = din;
		list = newNode;
		return 0;
	}

	node* head = list;
	do {
		if (list->next == nullptr)
		{
			node* newNode = new node();
			newNode->data = din;
			list->next = newNode;
			list = head;
			return 0;
		}
		list = list->next;
	} while (list != nullptr);
}

int fifo::rd_en(node** list, int &dout)
{
	if (list == nullptr) return 1;

	node* head = *list;
	dout = head->data;
	if (head->next == nullptr)
	{
		delete head;
		*list = nullptr;
		return 0;
	}
	else
	{
		*list = head->next;
		delete head;
		return 0;
	}
}

int fifo::data_count(node* list, int &wordCount)
{
	if (list == nullptr) return 1;

	wordCount = 0;
	do {
		++wordCount;
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int fifo::rst(node** list)
{
	if (*list == nullptr) return 1;

	do {
		node* dummy = *list;
		*list = dummy->next;
		delete dummy;
	} while (*list != nullptr);
	return 0;
}

int fifo::print(node* list)
{
	if (list == nullptr) return 1;

	int tempPos = 0;
	std::cout << "#\tdata:\tcurr:\t\t\tnext:\n";
	do {
		std::cout << tempPos << '\t' << list->data << '\t' << list << '\t' << list->next << '\n';
		++tempPos;
		list = list->next;
	} while (list != nullptr);
	std::cout << '\n';
	return 0;
}