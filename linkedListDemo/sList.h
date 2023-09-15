#pragma once
#include "nodes.h"
// sweeney's hand-rolled singly linked list.

class sList
{
public:
	node* init(int data);
	int addNodeFront(node *list, int data);
	void addNodeBack(node *list, int data);
	int addNodeByPos(node* list, int data, int pos);
	void deleteNodeFront(node** list);
	int deleteNodeBack(node* list);
	void deleteNode(node *list, int pos);
	void deleteAfter(node* list, int pos);
	int deleteNodeByPtr(node** list, node* ptr);
	int returnPtrByPos(node* list, int pos, node* &ptr);
	int returnPosByPtr(node* list, int &pos, node* ptr);
	int returnDataByPos(node* list, int &data, int pos);
	int returnDataByPtr(node* list, int &data, node* ptr);
	int updateDataByPos(node* list, int data, int pos);
	int updateDataByPtr(node* list, int data, node* ptr);
	int findDataReturnPos(node* list, int data, int &pos);
	int findDataReturnPtr(node* list, int data, node* &ptr);
	void clear(node** list);
	int isEmpty(node* list);
	int size(node *list);
	void print(node *list);
};