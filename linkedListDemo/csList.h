#pragma once
#include "nodes.h"

class csList
{
public:
	node* init(int data);
	int addNodeFront(node* list, int data);
	int addNodeBack(node* list, int data);
	int deleteNodeFront(node** list);
	int deleteNodeBack(node** list);
	int deleteNodeByPos(node** list, int pos);
	int deleteNodeByPtr(node** list, node* ptr);
	int returnPtrByPos(node* list, int pos, node* &ptr);
	int returnPosByPtr(node* list, int &pos, node* ptr);
	int returnDataByPos(node* list, int &data, int pos);
	int updateDataByPos(node* list, int pos, int data);
	int clear(node** list);
	int size(node* list, int &nodeCount);
	int isEmpty(node* list);
	int print(node* list);
	int reverse(node** list);
};