#pragma once
#include <iostream>
#include "nodes.h"

class stack
{
public:
	void push(node* list, int data);
	int pop(node** list);
	void print(node* list);
};