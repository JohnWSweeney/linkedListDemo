#pragma once
#include "nodes.h"
// sweeney's hand-rolled circular singly linked list.
//
// error codes:
// 0	no error.
// 1	list is nullptr.
// 2	ptr is nullptr.
// -1	pos/ptr not in list.

class csList
{
public:
	node* init(int data);
	int addNodeFront(node* list, int data);
	int addNodeBack(node* list, int data);
	int addNodeByPos(node* list, int data, int pos);
	int deleteNodeFront(node** list);
	int deleteNodeBack(node** list);
	int deleteNodeByPos(node** list, int pos);
	int deleteNodeByPtr(node** list, node* ptr);
	int returnPtrByPos(node* list, int pos, node* &ptr);
	int returnPosByPtr(node* list, int &pos, node* ptr);
	int returnDataByPos(node* list, int &data, int pos);
	int returnDataByPtr(node* list, int &data, node* ptr);
	int updateDataByPos(node* list, int pos, int data);
	int updateDataByPtr(node* list, int data, node* ptr);
	int findDataReturnPos(node* list, int data, int &pos);
	int findDataReturnPtr(node* list, int data, node* &ptr);
	int findMinReturnPos(node* list, int &min, int &pos);
	int findMinReturnPtr(node* list, int &min, node* &ptr);
	int findMaxReturnPos(node* list, int &max, int &pos);
	int findMaxReturnPtr(node* list, int &max, node* &ptr);
	int clear(node** list);
	int size(node* list, int &nodeCount);
	int isEmpty(node* list);
	int print(node* list);
	int reverse(node** list);
};