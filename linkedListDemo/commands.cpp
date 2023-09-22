#include "commands.h"

std::vector<std::string> listTypes = { "sList", "dList", "csList", "cdList", "fifo", "stack" };

std::vector<std::string> sListFuncsInts = { "init", "addNodeFront", "addNodeBack", "addNodeByPos", "returnPtrByPos", "returnPosByPtr", "returnDataByPos", "updateDataByPos", "updateDataByPtr", "findDataReturnPos", "findDataReturnPtr" };
std::vector<std::string> sListFuncsNoInts = { "deleteNodeFront", "deleteNodeBack", "deleteNodeByPtr", "returnPosByPtr", "returnDataByPtr", "clear", "isEmpty", "size", "print", "addNodes" };

std::vector<std::string> dListFuncInts = { "init", "addNodeFront", "addNodeBack", "returnPtrByPos", "returnDataByPos", "updateDataByPos", "findDataReturnPos", "findDataReturnPtr" };
std::vector<std::string> dListFuncNoInts = { "returnPosByPtr", "clear", "isEmpty", "size", "print", "addNodes", "clearPtr" };

std::vector<std::string> csListFuncsInts = { "init", "addNodeFront", "addNodeBack" };
std::vector<std::string> csListFuncsNoInts = { "deleteNodeFront", "deleteNodeBack", "isEmpty", "size", "print" };

std::vector<std::string> cdListFuncsInts = { "init", "addNodeFront", "addNodeBack", "deleteNodeByPos", "returnPtrByPos" };
std::vector<std::string> cdListFuncsNoInts = { "deleteNodeFront", "deleteNodeBack", "returnPosByPtr", "clear", "isEmpty", "size", "print", "addNodes"};

std::vector<std::string> fifoFuncsInts = { "init", "write" };
std::vector<std::string> fifoFuncsNoInts = { "read", "deleteNodeBack", "size", "print" };

std::vector<std::string> stackFuncsInts = { "init", "push" };
std::vector<std::string> stackFuncsNoInts = { "pop", "clear", "isEmpty", "size", "print" };

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

int populateCmd(std::vector<std::string> tokens, cmd &cmd)
{
	int result;
	// on start, check if user entered valid list type.
	if (cmd.listType.empty())
	{
		result = checkStringVector(tokens[1], listTypes, cmd.listType);
		if (result == 1)
		{
			std::cout << "Invalid list type.\n";
			return 1;
		}

		// if valid, populate cmd func string vectors.
		if (cmd.listType == "sList")
		{
			cmd.funcsInts = sListFuncsInts;
			cmd.funcsNoInts = sListFuncsNoInts;
		}
		else if (cmd.listType == "dList")
		{
			cmd.funcsInts = dListFuncInts;
			cmd.funcsNoInts = dListFuncNoInts;
		}
		else if (cmd.listType == "csList")
		{
			cmd.funcsInts = csListFuncsInts;
			cmd.funcsNoInts = csListFuncsNoInts;
		}
		else if (cmd.listType == "cdList")
		{
			cmd.funcsInts = cdListFuncsInts;
			cmd.funcsNoInts = cdListFuncsNoInts;
		}
		else if (cmd.listType == "fifo")
		{
			cmd.funcsInts = fifoFuncsInts;
			cmd.funcsNoInts = fifoFuncsNoInts;
		}
		else if (cmd.listType == "stack")
		{
			cmd.funcsInts = stackFuncsInts;
			cmd.funcsNoInts = stackFuncsNoInts;
		}
		return 0;
	}

	// check if user entered valid function for list type.
		// first, check if user command also requires an integer.
	result = checkStringVector(tokens[0], cmd.funcsNoInts, cmd.function);
	if (result == 0)
	{
		return 0;
	}
	else
	{
		// else, get the non integer-requiring command.
		result = checkStringVector(tokens[0], cmd.funcsInts, cmd.function);
		if (result == 0)
		{
			// first, check if user entered at least two tokens (commands).
			if (tokens.size() < 2)
			{
				std::cout << "Too few commands entered.\n";
				return 1;
			}
			else if (tokens.size() == 2)
			{
				result = getInteger(tokens[1], cmd.input1);
				if (result == 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else if (tokens.size() == 3)
			{
				result = getInteger(tokens[1], cmd.input1);
				if(result == 1)
				{
					return 1;
				}
				result = getInteger(tokens[2], cmd.input2);
				if (result == 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		else
		{
			std::cout << "Invalid function.\n";
			return 1;
		}
	}
}