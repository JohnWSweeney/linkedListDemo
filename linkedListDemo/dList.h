#pragma once
#include "nodes.h"
// sweeney's hand-rolled doubly linked list.

class dList
{
public:
	dNode* init(int data);
	int addNodeFront(dNode** list, int data);
	int addNodeBack(dNode* list, int data);
	int clear(dNode** list);
	int size(dNode* list, int &nodeCount);
	int isEmpty(dNode* list);
	int print(dNode* list);
};