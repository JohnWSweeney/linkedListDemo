#include "sll.h"
// sweeney's roll-your-own singly linked list.

void sll::addNodeEnd(node *head, int data)
{
	node *newNode = new node();
	newNode->data = data;
	newNode->next = NULL;

	node *temp = head;
	do {
		if (temp->next == NULL)
		{
			temp->next = newNode;
			return;
		}
		temp = temp->next;
	} while (temp != NULL);
}

int sll::size(node *head)
{
	int nodeCount = 0;
	node *temp = head;
	do {
		++nodeCount;
		temp = temp->next;
	} while (temp != NULL);
	return nodeCount;
}

void sll::printList(node *node)
{
	do {
		std::cout << node->data << '\n';
		node = node->next;
	} while (node != NULL);
	std::cout << '\n';
}