#pragma once
#include <iostream>
#include "nodes.h"
// sweeney's hand-rolled circular doubly linked list.

class cdList
{
public:
	dNode* init(int data);
	int addNodeFront(dNode* list, int data);
	int addNodeBack(dNode* list, int data);
	int deleteNodeFront(dNode** list);
	int deleteNodeBack(dNode* list);
	dNode* returnPtrByPos(dNode* list, int pos);
	int size(dNode* list);
	int isEmpty(dNode*);
	void print(dNode* list);
	void printReverse(dNode* list);
};