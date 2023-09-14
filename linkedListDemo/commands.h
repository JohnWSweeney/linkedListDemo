#pragma once
#include <iostream>
#include <string>
#include <vector>

struct cmd
{
	std::string listType;
	std::vector<std::string> funcsInts;
	std::vector<std::string> funcsNoInts;
	std::string function;
	int input1;
	int input2;
	int output;
};

int populateCmd(std::vector<std::string> tokens, cmd &cmd);