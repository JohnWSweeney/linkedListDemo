#pragma once
#include <iostream>
#include "nodes.h"

class fifo
{
public:
	void write(node* list, int data);
	int read(node*& list);
	int size(node* list);
	void clear(node* list);
	void print(node* list);
};

