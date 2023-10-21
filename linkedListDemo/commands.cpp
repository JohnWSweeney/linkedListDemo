#include "commands.h"
#include "atomicBool.h"

std::vector<std::string> listTypes = { "sList", "dList", "csList", "cdList", "fifo", "stack", "queue" };

std::vector<std::string> listFuncs = { "deleteNodeFront", "deleteNodeBack", "deleteNodeByPtr", "deleteBeforePtr", "deleteAfterPtr", "returnPosByPtr", "returnDataByPtr", "findMinReturnPos", "findMinReturnPtr", "findMaxReturnPos", "findMaxReturnPtr", "findTailReturnPos", "findTailReturnPtr", "movePtrToFront", "movePtrToBack", "movePtrUp", "movePtrDown", "clear", "isEmpty", "size", "print", "reverse", "addNodes", "clearPtr", "shuffle" };
std::vector<std::string> listFuncsInts = { "init", "addNodeFront", "addNodeBack", "addNodeByPos", "deleteNodeByPos", "deleteBeforePos", "deleteAfterPos", "returnPtrByPos", "returnDataByPos", "updateDataByPos", "updateDataByPtr", "findDataReturnPos", "findDataReturnPtr", "movePosToFront", "movePosToBack", "movePosUp", "movePosDown", "addRandomNodes", "swap" };
std::vector<std::string> listFuncsBool = { "bubbleSort", "selectionSort" };

std::vector<std::string> stackFuncs = { "pop", "top", "clear", "isEmpty", "size", "print" };
std::vector<std::string> stackFuncsInts = { "push" };

std::vector<std::string> queueFuncs = { "pop", "front", "back", "clear", "isEmpty", "size", "print" };
std::vector<std::string> queueFuncsInts = { "push" };

std::vector<std::string> fifoFuncsInts = { "config", "write" };
std::vector<std::string> fifoFuncs = { "read", "clear", "size", "print" };

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

int populateCmd(std::vector<std::string> tokens, cmd &cmd)
{
	int result;
	if (tokens[0] == "start")
	{
		if (status == false)
		{
			result = checkStringVector(tokens[1], listTypes, cmd.listType);
			if (result != 0)
			{
				std::cout << "Invalid list or application type.\n";
				return 1;
			}
			else return result;
		}
		else
		{
			std::cout << "Only one demo can be run at a time.\n";
			return 1;
		}
	}

	// lists.
	else if (cmd.listType == "sList" or cmd.listType == "dList" or cmd.listType == "csList" or cmd.listType == "cdList")
	{
		// check if command is a valid integer-requiring function.
		result = checkStringVector(tokens[0], listFuncsInts, cmd.function);
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
		result = checkStringVector(tokens[0], listFuncsBool, cmd.function);
		if(result == 0)
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
		result = checkStringVector(tokens[0], listFuncs, cmd.function);
		if (result == 1)
		{
			std::cout << "Invalid function.\n";
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// application: stack.
	else if (cmd.listType == "stack")
	{
		// check if command is a valid integer-requiring function.
		result = checkStringVector(tokens[0], stackFuncsInts, cmd.function);
		if (result == 0)
		{
			// check if two commands (function, int1) were entered.
			if (tokens.size() < 2)
			{
				std::cout << "Too few commands entered.\n";
				return 1;
			}
			// get the integer.
			result = getInteger(tokens[1], cmd.input1);
			return result;
		}
		else
		{
			// check if command is a valid non-integer-requiring function.
			result = checkStringVector(tokens[0], stackFuncs, cmd.function);
			if (result == 1)
			{
				std::cout << "Invalid function.\n";
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	// application: queue.
	else if (cmd.listType == "queue")
	{
		// check if command is a valid integer-requiring function.
		result = checkStringVector(tokens[0], queueFuncsInts, cmd.function);
		if (result == 0)
		{
			// check if two commands (function, int1) were entered.
			if (tokens.size() < 2)
			{
				std::cout << "Too few commands entered.\n";
				return 1;
			}
			// get the integer.
			result = getInteger(tokens[1], cmd.input1);
			return result;
		}
		else
		{
			// check if command is a valid non-integer-requiring function.
			result = checkStringVector(tokens[0], queueFuncs, cmd.function);
			if (result == 1)
			{
				std::cout << "Invalid function.\n";
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	// application: fifo.
	else if (cmd.listType == "fifo")
	{
		// check if command is a valid integer-requiring function.
		result = checkStringVector(tokens[0], fifoFuncsInts, cmd.function);
		if (result == 0)
		{
			// check if two commands (function, int1) were entered.
			if (tokens.size() < 2)
			{
				std::cout << "Too few commands entered.\n";
				return 1;
			}
			// get the integer.
			result = getInteger(tokens[1], cmd.input1);
			return result;
		}
		else
		{
			// check if command is a valid non-integer-requiring function.
			result = checkStringVector(tokens[0], fifoFuncs, cmd.function);
			if (result == 1)
			{
				std::cout << "Invalid function.\n";
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		std::cout << "Invalid command.\n";
		return 1;
	}
}