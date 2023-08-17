#pragma once
#include <iostream>
// sweeney's roll-your-own singly linked list.

struct node
{
	int data;
	node *next;
};

class sll
{
public:
	void addNodeEnd(node *head, int data);
	int size(node *head);
	void printList(node *node);
};

