#pragma once
#include <iostream>
#include "nodes.h"
// sweeney's hand-rolled singly linked list.

class sList
{
public:
	node* initList(int data);
	void addNode(node *list, int data, int pos);
	void addNodeFront(node *list, int data);
	void addNodeBack(node *list, int data);
	int accessNode(node *list, int pos);
	int updateNodeData(node *list, int data, int pos);
	void deleteNode(node *list, int pos);
	void deleteAfter(node* list, int pos);
	void clear(node* list);
	int size(node *list);
	void printList(node *list, bool showDetails);
	int find(node *list, int data);
};