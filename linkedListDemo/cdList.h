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
	int returnPtrByPos(dNode* list, int pos, dNode* &ptr);
	int returnPosByPtr(dNode* list, int &pos, dNode* ptr);
	int clear(dNode** list);
	int isEmpty(dNode* list);
	int size(dNode* list, int &nodeCount);
	int print(dNode* list);
};