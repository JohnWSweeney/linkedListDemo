#pragma once
#include <iostream>
// sweeney's hand-rolled singly linked list.

struct node
{
	int data;
	node *next;
};

class sll
{
public:
	void addNode(node *list, int data, int pos);
	void addNodeFront(node *list, int data);
	void addNodeBack(node *list, int data);
	int accessNode(node *list, int pos);
	void updateNodeData(node *list, int data, int pos);
	int size(node *list);
	void printList(node *list, bool showDetails);
};

