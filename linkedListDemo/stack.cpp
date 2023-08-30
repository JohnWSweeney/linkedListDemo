#include "stack.h"

node* stack::init(int data)
{
	node* newNode = new node();
	newNode->data = data;
	return newNode;
}

void stack::push(node* list, int data)
{
	node* newNode = new node();
	newNode->data = list->data;
	newNode->next = list->next;
	list->data = data;
	list->next = newNode;
}

int stack::pop(node** list)
{
	node* dummy = *list;
	*list = dummy->next;
	int temp = dummy->data;
	delete dummy;
	return temp;
}

void stack::print(node* list)
{
	do {
		std::cout << list->data << '\t' << list->next << '\n';
		list = list->next;
	} while (list != NULL);
	std::cout << '\n';
}