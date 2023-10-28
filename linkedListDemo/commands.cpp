#include "commands.h"
#include "atomicBool.h"

std::vector<std::string> demoTypes = { "sList", "dList", "csList", "cdList", "fifo", "stack", "queue" };

std::vector<std::string> listFunc = { "deleteNodeFront", "deleteNodeBack", "deleteNodeByPtr", "deleteBeforePtr", "deleteAfterPtr", "returnPosByPtr", "returnFrontData", "returnBackData", "returnDataByPtr", "findMinReturnPos", "findMinReturnPtr", "findMaxReturnPos", "findMaxReturnPtr", "findTailReturnPos", "findTailReturnPtr", "movePtrToFront", "movePtrToBack", "movePtrUp", "movePtrDown", "clear", "isEmpty", "size", "print", "reverse", "addNodes", "clearPtr", "shuffle" };
std::vector<std::string> listFuncInt = { "init", "addNodeFront", "addNodeBack", "addNodeByPos", "deleteNodeByPos", "deleteBeforePos", "deleteAfterPos", "returnPtrByPos", "returnDataByPos", "updateDataByPos", "updateDataByPtr", "findDataReturnPos", "findDataReturnPtr", "movePosToFront", "movePosToBack", "movePosUp", "movePosDown", "addRandomNodes", "swap" };
std::vector<std::string> listFuncBool = { "bubbleSort", "selectionSort" };

std::vector<std::string> stackFunc = { "pop", "top", "clear", "isEmpty", "size", "print" };
std::vector<std::string> stackFuncInt = { "push" };

std::vector<std::string> queueFunc = { "pop", "front", "back", "clear", "isEmpty", "size", "print" };
std::vector<std::string> queueFuncInt = { "push" };

std::vector<std::string> fifoFuncInt = { "config", "write" };
std::vector<std::string> fifoFunc = { "read", "clear", "size", "print" };

int checkStringVector(std::string token, std::vector<std::string> strVector, std::string &cmdStr)
{
	if (token.empty())
	{
		return 1;
	}

	auto result = std::find(strVector.begin(), strVector.end(), token);
	if (result != strVector.end())
	{
		cmdStr = token;
		return 0;
	}
	else
	{
		return 1;
	}
}

int getInteger(std::string token, int &integer)
{
	if (token.empty())
	{
		std::cout << "No integer entered.\n";
		return 1;
	}

	try {
		integer = std::stoi(token);
		return 0;
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid integer.\n";
		return 1;
	}
	catch (std::out_of_range)
	{
		std::cout << "Integer out of range.\n";
		return 1;
	}
}

int getBool(std::string token, bool &boolean)
{
	if (token.empty())
	{
		std::cout << "No boolean string entered.\n";
		return 1;
	}

	if (token == "true" or token == "asc")
	{
		boolean = true;
		return 0;
	}
	else if (token == "false" or token == "desc")
	{
		boolean = false;
		return 0;
	}
	else
	{
		std::cout << "Invalid boolean string.\n";
		return 1;
	}
}

void populateFunctionLists(cmd &cmd)
{
	if (cmd.demoType == "sList" or cmd.demoType == "dList" or cmd.demoType == "csList" or cmd.demoType == "cdList")
	{
		cmd.func = listFunc;
		cmd.funcInt = listFuncInt;
		cmd.funcBool = listFuncBool;
	}
	else if (cmd.demoType == "stack")
	{
		cmd.func = stackFunc;
		cmd.funcInt = stackFuncInt;
		cmd.funcBool = {};
	}
	else if (cmd.demoType == "queue")
	{
		cmd.func = queueFunc;
		cmd.funcInt = queueFuncInt;
		cmd.funcBool = {};
	}
	else if (cmd.demoType == "fifo")
	{
		cmd.func = fifoFunc;
		cmd.funcInt = fifoFuncInt;
		cmd.funcBool = {};
	}
}

int checkFunctionGetVariables(std::vector<std::string> tokens, cmd &cmd)
{
	int result;
	// check if command is a valid integer-requiring function.
	result = checkStringVector(tokens[0], cmd.funcInt, cmd.function);
	if (result == 0)
	{
		// check if function requires three integers.
		if (cmd.function == "addRandomNodes")
		{
			// check if three commands (function, int1, int2, int3) were entered.
			if (tokens.size() < 4)
			{
				std::cout << "Too few commands entered.\n";
				return 1;
			}
			// if so, get the first integer.
			result = getInteger(tokens[1], cmd.input1);
			if (result == 1) return 1;
			// then get the second integer.
			result = getInteger(tokens[2], cmd.input2);
			if (result == 1) return 1;
			// then get the third integer.
			result = getInteger(tokens[3], cmd.input3);
			return result;
		}

		// check if function requires two integers.
		if (cmd.function == "addNodeByPos" or cmd.function == "updateDataByPos" or cmd.function == "swap")
		{
			// check if three commands (function, int1, int2) were entered.
			if (tokens.size() < 3)
			{
				std::cout << "Too few commands entered.\n";
				return 1;
			}
			// if so, get the first integer.
			result = getInteger(tokens[1], cmd.input1);
			if (result == 1) return 1;
			// then get the second integer.
			result = getInteger(tokens[2], cmd.input2);
			return result;
		}

		// check if two commands (function, int1) were entered.
		if (tokens.size() < 2)
		{
			std::cout << "Too few commands entered.\n";
			return 1;
		}
		// get the first (or only) integer.
		result = getInteger(tokens[1], cmd.input1);
		return result;
	}

	// check if command is a valid boolean-requiring function.
	result = checkStringVector(tokens[0], cmd.funcBool, cmd.function);
	if (result == 0)
	{
		// check if two commands (function, boolean) were entered.
		if (tokens.size() < 2)
		{
			std::cout << "Too few commands entered.\n";
			return 1;
		}
		result = getBool(tokens[1], cmd.isAscending);
		return result;
	}

	// check if command is a valid non-integer-requiring function.
	result = checkStringVector(tokens[0], cmd.func, cmd.function);
	return result;
}

int populateCmd(std::vector<std::string> tokens, cmd &cmd)
{
	int result;
	// check if user is starting new demo or entering commands for running demo.
	if (tokens[0] == "start")
	{
		// check if a demo is currently running.
		if (status == false)
		{
			// check if user entered a valid demo type.
			result = checkStringVector(tokens[1], demoTypes, cmd.demoType);
			if (result == 0)
			{
				populateFunctionLists(cmd);
				return 0;
			}
			else
			{
				std::cout << "Invalid demo type.\n";
				return 1;
			}
		}
		else
		{
			std::cout << "Only one demo can run at a time.\n";
			return 1;
		}
	}
	else // demo is running, get new commands.
	{
		// check if user enter a valid function for the demo, get integers/bools for function as needed.
		result = checkFunctionGetVariables(tokens, cmd);
		if (result == 1)
		{
			std::cout << "Invalid function.\n";
		}
		return result;
	}
}