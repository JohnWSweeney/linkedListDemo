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
	void printList(node *node);
};

