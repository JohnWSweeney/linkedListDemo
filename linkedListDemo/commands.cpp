#include "commands.h"

std::vector<std::string> listTypes = { "cs", "fifo" };
std::vector<std::string> functionsWithIntegers = { "init", "addNodeFront", "addNodeBack", "write" };
std::vector<std::string> functionsNoIntegers = { "deleteNodeFront", "deleteNodeBack", "read", "isEmpty", "size", "print", "start", "stop", "exit" };

int checkListType(std::string token, std::string &listType)
{
	auto result = std::find(listTypes.begin(), listTypes.end(), token);
	if (result != listTypes.end())
	{
		listType = token;
		return 0;
	}
	else
	{
		std::cout << "Invalid list type.\n";
		return 1;
	}
}

int checkFunction(std::string token, bool &hasInt, std::string &function)
{
	auto result = std::find(functionsWithIntegers.begin(), functionsWithIntegers.end(), token);
	if (result != functionsWithIntegers.end())
	{
		hasInt = true;
		function = token;
		return 0;
	}
	else
	{
		auto result = std::find(functionsNoIntegers.begin(), functionsNoIntegers.end(), token);
		if (result != functionsNoIntegers.end())
		{
			hasInt = false;
			function = token;
			return 0;
		}
		else
		{
			std::cout << "Invalid function.\n";
			return 1;
		}
	}
}

int getInteger(std::string token, int &integer)
{
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
	int result = checkFunction(tokens[0], cmd.hasInt, cmd.function);
	if (result != 0)
	{
		return 1;
	}

	if (cmd.function == "start")
	{
		int listResult = checkListType(tokens[1], cmd.listType);
		if (listResult != 0)
		{
			return 1;
		}
	}

	if (cmd.hasInt == true)
	{
		result = getInteger(tokens[1], cmd.data);
		if (result != 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}



}