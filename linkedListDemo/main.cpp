#include <iostream>
#include "random.h"
#include "sll.h"

int main()
{
	std::cout << "linkedListDemo v0.0.0\n\n";

	node *head = new node();
	node *two = new node();
	node *three = new node();

	head->data = 1;
	head->next = two;
	two->data = 2;
	two->next = three;
	three->data = 3;
	three->next = NULL;

	sll sll;
	sll.printList(head);
}