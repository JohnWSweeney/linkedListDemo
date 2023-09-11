#include "commands.h"

std::vector<std::string> listTypes = { "cs", "fifo" };

std::vector<std::string> csFuncsInts = { "init", "addNodeFront", "addNodeBack" };
std::vector<std::string> csFuncsNoInts = { "deleteNodeFront", "deleteNodeBack", "isEmpty", "size", "print" };

std::vector<std::string> fifoFuncsInts = { "init", "write" };
std::vector<std::string> fifoFuncsNoInts = { "read", "deleteNodeBack", "size", "print" };

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
	// check if user entered at least two tokens (commands).
	if (tokens.size() < 2)
	{
		std::cout << "Too few commands entered.\n";
		return 1;
	}

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
		if (cmd.listType == "cs")
		{
			cmd.funcsInts = csFuncsInts;
			cmd.funcsNoInts = csFuncsNoInts;
		}
		else if (cmd.listType == "fifo")
		{
			cmd.funcsInts = fifoFuncsInts;
			cmd.funcsNoInts = fifoFuncsNoInts;
		}
		return 0;
	}

	// check if user entered valid function for list type.
	// first, check if user command also requires an integer.
	result = checkStringVector(tokens[0], cmd.funcsInts, cmd.function);
	if (result == 0)
	{
		// if so, get the integer.
		int newResult = getInteger(tokens[1], cmd.data);
		if (newResult == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		// else, get the non integer requiring command.
		int newResult = checkStringVector(tokens[0], cmd.funcsNoInts, cmd.function);
		if (newResult == 0)
		{
			return 0;
		}
		std::cout << "Invalid function.\n";
		return 1;
	}
}