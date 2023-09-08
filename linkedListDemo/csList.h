#pragma once
#include "nodes.h"

class csList
{
public:
	node* init(int data);
	int addNodeFront(node* list, int data);
	int addNodeBack(node* list, int data);
	int deleteNodeFront(node*& list);
	int deleteNodeBack(node* list);
	int deleteNodeByPtr(node* list, node* ptr);
	node* returnPtrByPos(node* list, int pos);
	int returnPosByPtr(node* list, node* ptr);
	int returnDataByPos(node* list, int pos);
	int updateNodeByPos(node* list, int pos, int data);
	int size(node* list);
	int isEmpty(node* list);
	void print(node* list);
};