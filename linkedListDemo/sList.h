#pragma once
#include "nodes.h"
// sweeney's hand-rolled singly linked list.

class sList
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
	int updateDataByPos(node* list, int data, int pos);
	int updateDataByPtr(node* list, int data, node* ptr);
	int findDataReturnPos(node* list, int data, int &pos);
	int findDataReturnPtr(node* list, int data, node* &ptr);
	int findMinReturnPos(node* list, int &min, int &pos);
	int findMinReturnPtr(node* list, int &min, node* &ptr);
	int findMaxReturnPos(node* list, int &max, int &pos);
	int findMaxReturnPtr(node* list, int &max, node* &ptr);
	int moveToFrontByPos(node** list, int pos);
	int clear(node** list);
	int isEmpty(node* list);
	int size(node* list, int &nodeCount);
	int print(node* list);
	int reverse(node** list);
};