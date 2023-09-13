#pragma once
#include "nodes.h"
// sweeney's hand-rolled singly linked list.

class sList
{
public:
	node* init(int data);
	int addNodeFront(node *list, int data);
	void addNodeBack(node *list, int data);
	void addNode(node *list, int data, int pos);
	void deleteNodeFront(node** list);
	int deleteNodeBack(node* list);
	void deleteNode(node *list, int pos);
	void deleteAfter(node* list, int pos);
	int deleteNodeByPtr(node** list, node* ptr);
	int returnPtrByPos(node* list, int pos, node* &ptr);
	int accessNode(node *list, int pos);
	int updateNodeData(node *list, int data, int pos);
	int find(node *list, int data);
	void clear(node** list);
	int isEmpty(node* list);
	int size(node *list);
	void print(node *list);
};