#include "stack.h"

node* stack::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	return newNode;
}

void stack::push(node* list, int data)
{
	if (list == NULL)
	{
		std::cout << "Stack is empty.\n";
		return;
	}

	node* newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
}

int stack::pop(node** list)
{
	if (list == NULL)
	{
		std::cout << "Stack is empty.\n";
		return INT_MIN;
	}

	node* dummy = *list;
	*list = dummy->next;
	int temp = dummy->data;
	delete dummy;
	return temp;
}

void stack::clear(node** list)
{
	if (list == NULL)
	{
		std::cout << "Stack is empty.\n";
		return;
	}

	do {
		node* dummy = *list;
		*list = dummy->next;
		delete dummy;
	} while (*list != NULL);
}

int stack::isEmpty(node* list)
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

int stack::size(node* list)
{
	if (list == NULL)
	{
		std::cout << "Stack is empty.\n";
		return -1;
	}

	int nodeCount = 0;
	do {
		++nodeCount;
		list = list->next;
	} while (list != NULL);
	return nodeCount;
}

void stack::print(node* list)
{
	if (list == NULL)
	{
		std::cout << "Stack is empty.\n";
		return;
	}

	do {
		std::cout << list->data << '\t' << list->next << '\n';
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
}