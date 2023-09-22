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
	int size(dNode* list, int &nodeCount);
	int print(dNode* list);
};