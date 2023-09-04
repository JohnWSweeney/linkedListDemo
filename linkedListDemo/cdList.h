#pragma once
#include <iostream>
#include "nodes.h"
// sweeney's hand-rolled circular doubly linked list.

class cdList
{
public:
	dNode* init(int data);
	void addNodeBack(dNode* list, int data);
	void deleteNodeBack(dNode*list);
	int isEmpty(dNode* list);
	void print(dNode* list);
};