#pragma once
//#include <iostream>
#include "nodes.h"
// sweeney's hand-rolled first-in-first-out (FIFO) class.

class fifo
{
public:
	int wr_en(node* &list, int din);
	int rd_en(node** list, int &dout);
	int data_count(node* list, int &wordCount);
	int rst(node** list);
	int print(node* list);
};