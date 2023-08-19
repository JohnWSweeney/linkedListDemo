#pragma once
#include <iostream>
// sweeney's hand-rolled doubly linked list.

struct dNode
{
	int data;
	dNode *next = NULL;
	dNode *prev = NULL;
};

class dList
{
public:
	void addNodeBack(dNode *list, int data);
	void addNodeFront(dNode *list, int data);
	int size(dNode *list);
	void printList(dNode *list);
};

