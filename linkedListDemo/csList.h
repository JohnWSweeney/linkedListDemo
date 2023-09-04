#pragma once
#include "nodes.h"

class csList
{
public:
	node* init(int data);
	void addNodeFront(node* list, int data);
	void addNodeBack(node* list, int data);
	int accessNode(node* list, int pos);
	int updateNode(node* list, int pos, int data);
	int size(node* list);
	int isEmpty(node* list);
	void print(node* list);
};