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
	int data;
};

int populateCmd(std::vector<std::string> tokens, cmd &cmd);