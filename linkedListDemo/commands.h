#pragma once
#include <iostream>
#include <string>
#include <vector>

struct cmd
{
	std::string listType;
	std::string function;
	bool hasInt;
	int data;
};

int checkListType(std::string token, std::string &listType);
int checkFunction(std::string token, bool &hasInt, std::string &function);
int getInteger(std::string token, int &integer);
int populateCmd(std::vector<std::string> tokens, cmd &cmd);