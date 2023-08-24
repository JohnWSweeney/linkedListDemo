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
	void deleteNode(dNode* list, int pos);
	void deleteAfter(dNode* list, int pos);
	void clear(dNode* list);
	int size(dNode *list);
	void printList(dNode *list, bool showDetails);
	int find(dNode *list, int data);
};