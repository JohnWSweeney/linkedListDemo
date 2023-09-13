#pragma once
#include "nodes.h"

class stack
{
public:
	node* init(int data);
	void push(node* list, int data);
	int pop(node** list);
	void clear(node** list);
	int isEmpty(node* list);
	int size(node* list);
	void print(node* list);
};