#pragma once
#include <iostream>
// sweeney's hand-rolled singly linked list.

struct sNode
{
	int data;
	sNode *next = NULL;
};

class sList
{
public:
	void addNode(sNode *list, int data, int pos);
	void addNodeFront(sNode *list, int data);
	void addNodeBack(sNode *list, int data);
	int accessNode(sNode *list, int pos);
	int updateNodeData(sNode *list, int data, int pos);
	void deleteNode(sNode *list, int pos);
	int size(sNode *list);
	void printList(sNode *list, bool showDetails);
	int find(sNode *list, int data);
};