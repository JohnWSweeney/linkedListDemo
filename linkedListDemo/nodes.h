#pragma once
#include <iostream>

struct node
{
	int data;
	node* next = NULL;
};

struct dNode
{
	int data;
	dNode* next = NULL;
	dNode* prev = NULL;
};