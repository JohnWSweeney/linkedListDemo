#pragma once
#include "nodes.h"
// sweeney's hand-rolled doubly linked list.

class dList
{
public:
	dNode* init(int data);
	int addNodeFront(dNode** list, int data);
	int addNodeBack(dNode* list, int data);
	int deleteNodeFront(dNode** list);
	int deleteNodeBack(dNode** list);
	int deleteNodeByPos(dNode** list, int pos);
	int returnPtrByPos(dNode* list, int pos, dNode* &ptr);
	int returnPosByPtr(dNode* list, int &pos, dNode* ptr);
	int returnDataByPos(dNode* list, int &data, int pos);
	int updateDataByPos(dNode* list, int data, int pos);
	int findDataReturnPos(dNode* list, int data, int &pos);
	int findDataReturnPtr(dNode* list, int data, dNode* &ptr);
	int clear(dNode** list);
	int size(dNode* list, int &nodeCount);
	int isEmpty(dNode* list);
	int print(dNode* list);
};