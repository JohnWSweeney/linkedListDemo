#pragma once
#include "nodes.h"
// sweeney's hand-rolled doubly linked list.

class dList
{
public:
	dNode* init(int data);
	int addNodeFront(dNode** list, int data);
	int addNodeBack(dNode* list, int data);
	int addNodeByPos(dNode* list, int data, int pos);
	int deleteNodeFront(dNode** list);
	int deleteNodeBack(dNode** list);
	int deleteNodeByPos(dNode** list, int pos);
	int deleteNodeByPtr(dNode** list, dNode* &ptr);
	int returnPtrByPos(dNode* list, int pos, dNode* &ptr);
	int returnPosByPtr(dNode* list, int &pos, dNode* ptr);
	int returnDataByPos(dNode* list, int &data, int pos);
	int returnDataByPtr(dNode* list, int &data, dNode* ptr);
	int updateDataByPos(dNode* list, int data, int pos);
	int updateDataByPtr(dNode* list, int data, dNode* ptr);
	int findDataReturnPos(dNode* list, int data, int &pos);
	int findDataReturnPtr(dNode* list, int data, dNode* &ptr);
	int findMinReturnPos(dNode* list, int &min, int &pos);
	int findMinReturnPtr(dNode* list, int &min, dNode* &ptr);
	int findMaxReturnPos(dNode* list, int &max, int &pos);
	int findMaxReturnPtr(dNode* list, int &max, dNode* &ptr);
	int clear(dNode** list);
	int size(dNode* list, int &nodeCount);
	int isEmpty(dNode* list);
	int print(dNode* list);
	int reverse(dNode** list);
};