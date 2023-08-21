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
	void addNodeFront(dNode *list, int data);
	void addNodeBack(dNode *list, int data);
	int accessNode(dNode *list, int pos);
	int updateNodeData(dNode *list, int data, int pos);
	int size(dNode *list);
	void printList(dNode *list, bool showDetails);
	int find(dNode *list, int data);
};