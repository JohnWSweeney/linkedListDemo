#pragma once
#include <iostream>
#include "nodes.h"

class stack
{
public:
	node* init(int data);
	void push(node* list, int data);
	int pop(node** list);
	void print(node* list);
};