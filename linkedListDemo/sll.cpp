#include "sll.h"
// sweeney's roll-your-own singly linked list.

void sll::printList(node *node)
{
	do {
		std::cout << node->data << '\n';
		node = node->next;
	} while (node != NULL);
}