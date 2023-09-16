#include "functions.h"
#include "sList.h"
#include "dList.h"
#include "csList.h"
#include "fifo.h"
#include "stack.h"
#include "atomicBool.h"

void sDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Singly linked list demo started.\n";
	sList slist;
	int result;
	int nodeCount;
	node* list = NULL;
	node* ptr = NULL;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "init")
		{
			list = slist.init(cmd.input1);
			slist.print(list);
		}
		else if (cmd.function == "addNodeFront")
		{
			result = slist.addNodeFront(list, cmd.input1);
			if (result == 0)
			{
				std::cout << "Node added to list front.\n";
				slist.print(list);
			}
			else
			{
				std::cout << "List is empty.\n\n";
			}
			
		}
		else if (cmd.function == "addNodeBack")
		{
			result = slist.addNodeBack(list, cmd.input1);
			if (result == 0)
			{
				slist.print(list);
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodeByPos")
		{
			result = slist.addNodeByPos(list, cmd.input1, cmd.input2);
			if (result == 0)
			{
				std::cout << "Postion added.\n\n";
				slist.print(list);
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n\n";
			}
			else if (result == -1)
			{
				std::cout << "Position is out of bounds.\n\n";
			}
		}
		else if (cmd.function == "deleteNodeFront")
		{
			result = slist.deleteNodeFront(&list);
			if (result == 0)
			{
				result = slist.print(list);
				if (result != 0)
				{
					std::cout << "List is empty.\n";
				}
			}
			if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeBack")
		{
			result = slist.deleteNodeBack(list);
			if (result == 0)
			{
				result = slist.print(list);
				if (result != 0)
				{
					std::cout << "List is empty.\n";
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeByPtr")
		{
			result = slist.deleteNodeByPtr(&list, ptr);
			if (result == 0)
			{
				std::cout << "Postion deleted.\n\n";
				slist.print(list);
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n\n";
			}
			else if (result == -1)
			{
				std::cout << "Pointer is null.\n\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer not in list.\n\n";
			}
		}
		else if (cmd.function == "returnPtrByPos")
		{
			result = slist.returnPtrByPos(list, cmd.input1, ptr);
			if (result == 0)
			{
				std::cout << "Pointer to position " << cmd.input1 << ": " << ptr << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Requested postition is out of bounds.\n";
			}
		}
		else if (cmd.function == "returnPosByPtr")
		{
			result = slist.returnPosByPtr(list, cmd.output, ptr);
			if (result == 0)
			{
				std::cout << "Pointer " << ptr << " is in position " << cmd.output << ".\n";
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n\n";
			}
			else if (result == -1)
			{
				std::cout << "Pointer is null.\n\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer not in list.\n\n";
			}
		}
		else if (cmd.function == "returnDataByPos")
		{
			result = slist.returnDataByPos(list, cmd.output, cmd.input1);
			if (result == 0)
			{
				std::cout << "Data in position " << cmd.input1 << ": " << cmd.output << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Positon is not in list.\n";
			}
		}
		else if (cmd.function == "returnDataByPtr")
		{
			result = slist.returnDataByPtr(list, cmd.output, ptr);
			if (result == 0)
			{
				std::cout << "Data in pointer " << ptr << ": " << cmd.output << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n\n";
			}
			else if (result == -1)
			{
				std::cout << "Pointer is null.\n\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer not in list.\n\n";
			}
		}
		else if (cmd.function == "updateDataByPos")
		{
			result = slist.updateDataByPos(list, cmd.input1, cmd.input2);
			if (result == 0)
			{
				std::cout << "List updated.\n";
				slist.print(list);
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Positon is not in list.\n";
			}
		}
		else if (cmd.function == "updateDataByPtr")
		{
			result = slist.updateDataByPtr(list, cmd.input1, ptr);
			if (result == 0)
			{
				std::cout << "List updated.\n";
				slist.print(list);
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Pointer is not in list.\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer is null.\n";
			}
		}
		else if (cmd.function == "findDataReturnPos")
		{
			result = slist.findDataReturnPos(list, cmd.input1, cmd.output);
			if (result == 0)
			{
				std::cout << "Data '" << cmd.input1 << "' found in position " << cmd.output << ".\n";
			}
			else if (result == 1)
			{
				std::cout << "list is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Data not found in list.\n";
			}
		}
		else if (cmd.function == "findDataReturnPtr")
		{
			result = slist.findDataReturnPtr(list, cmd.input1, ptr);
			if (result == 0)
			{
				std::cout << "Data '" << cmd.input1 << "' found in pointer " << ptr << ".\n";
			}
			else if (result == 1)
			{
				std::cout << "list is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Data not found in list.\n";
			}
		}
		else if (cmd.function == "clear")
		{
			result = slist.clear(&list);
			if (result == 0)
			{
				std::cout << "List cleared.\n";
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "isEmpty")
		{
			result = slist.isEmpty(list);
			if (result == 0)
			{
				std::cout << "List is not empty.\n";
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "size")
		{
			result = slist.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Node count: " << nodeCount << '\n';
			}
			else
			{
				std::cout << "List is empty.\n";
			}
			
		}
		else if (cmd.function == "print")
		{
			result = slist.print(list);
			if (result != 0)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodes")
		{
			for (int i = 0; i < 9; i++)
			{
				slist.addNodeBack(list, i * i * i);
			}
			slist.print(list);
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Singly linked list demo stopped.\n";
}

void dDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Doubly linked list demo started.\n";
	dList dlist;
	int result;
	int nodeCount;
	dNode* list = NULL;
	dNode* ptr = NULL;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "init")
		{
			list = dlist.init(cmd.input1);
			dlist.print(list);
		}
		else if (cmd.function == "addNodeFront")
		{
			result = dlist.addNodeFront(&list, cmd.input1);
			if (result == 0)
			{
				dlist.print(list);
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodeBack")
		{
			result = dlist.addNodeBack(list, cmd.input1);
			if (result == 0)
			{
				dlist.print(list);
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "returnPtrByPos")
		{
			result = dlist.returnPtrByPos(list, cmd.input1, ptr);
			if (result == 0)
			{
				std::cout << "Pointer to position " << cmd.input1 << ": " << ptr << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Position is out of bounds.\n";
			}
		}
		else if (cmd.function == "returnPosByPtr")
		{
			result = dlist.returnPosByPtr(list, cmd.output, ptr);
			if (result == 0)
			{
				std::cout << "Pointer " << ptr << " is in position " << cmd.output << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Pointer is not in list.\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer null.\n";
			}
		}
		else if (cmd.function == "returnDataByPos")
		{
			result = dlist.returnDataByPos(list, cmd.output, cmd.input1);
			if (result == 0)
			{
				std::cout << "Position " << cmd.input1 << " data: " << cmd.output << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Position is out of bounds.\n";
			}
		}
		else if (cmd.function == "clear")
		{
			result = dlist.clear(&list);
			if (result == 0)
			{
				std::cout << "List cleared.\n";
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "isEmpty")
		{
			result = dlist.isEmpty(list);
			if (result == 0)
			{
				std::cout << "List is not empty.\n";
			}
			else if (result == 1)
			{
				std::cout << "list is empty.\n";
			}
		}
		else if (cmd.function == "size")
		{
			result = dlist.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Node count: " << nodeCount << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "print")
		{
			result = dlist.print(list);
			if (result != 0)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodes")
		{
			if (list != NULL)
			{
				for (int i = 0; i < 9; i++)
				{
					dlist.addNodeBack(list, i * i * i * i);
				}
				dlist.size(list, nodeCount);
				std::cout << "Node count: " << nodeCount << '\n';
				dlist.print(list);
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Doubly linked list demo stopped.\n";
}

void csDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Circular singly linked list demo started.\n";
	csList cslist;
	int result;
	node* list = NULL;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "init")
		{
			list = cslist.init(cmd.input1);
			cslist.print(list);
		}
		else if (cmd.function == "addNodeFront")
		{
			cslist.addNodeFront(list, cmd.input1);
			cslist.print(list);
		}
		else if (cmd.function == "addNodeBack")
		{
			cslist.addNodeBack(list, cmd.input1);
			cslist.print(list);
		}
		else if (cmd.function == "deleteNodeFront")
		{
			cslist.deleteNodeFront(list);
			cslist.print(list);
		}
		else if (cmd.function == "deleteNodeBack")
		{
			cslist.deleteNodeBack(list);
			cslist.print(list);
		}
		else if (cmd.function == "isEmpty")
		{
			result = cslist.isEmpty(list);
			if (result == 0)
			{
				std::cout << "List is not empty.\n";
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "size")
		{
			std::cout << "Node count: " << cslist.size(list) << '\n';
			cslist.print(list);
		}
		else if (cmd.function == "print")
		{
			cslist.print(list);
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Circular singly linked list demo stopped.\n";
}

void fifoDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "FIFO demo started.\n";
	fifo fifo;
	node* list = NULL;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "init")
		{
			list = fifo.init(cmd.input1);
			fifo.print(list);
		}
		else if (cmd.function == "write")
		{
			fifo.write(list, cmd.input1);
			fifo.print(list);
		}
		else if (cmd.function == "read")
		{
			std::cout << "FIFO output: " << fifo.read(list) << '\n';
			fifo.print(list);
		}
		else if (cmd.function == "size")
		{
			std::cout << "Node count: " << fifo.size(list) << '\n';
			fifo.print(list);
		}
		else if (cmd.function == "print")
		{
			fifo.print(list);
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "FIFO demo stopped.\n";
}

void stackDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Stack demo started.\n";
	stack stack;
	int result;
	node* list = NULL;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "init")
		{
			list = stack.init(cmd.input1);
			stack.print(list);
		}
		else if (cmd.function == "push")
		{
			stack.push(list, cmd.input1);
			stack.print(list);
		}
		else if (cmd.function == "pop")
		{
			std::cout << "Stack output: " << stack.pop(&list) << '\n';
			stack.print(list);
		}
		else if (cmd.function == "clear")
		{
			stack.clear(&list);
			stack.print(list);
		}
		else if (cmd.function == "isEmpty")
		{
			result = stack.isEmpty(list);
			if (result == 0)
			{
				std::cout << "Stack is not empty.\n";
			}
			else
			{
				std::cout << "Stack is empty.\n";
			}
		}
		else if (cmd.function == "size")
		{
			std::cout << "Stack size: " << stack.size(list) << '\n';
			stack.print(list);
		}
		else if (cmd.function == "print")
		{
			stack.print(list);
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Stack dmeo stopped.\n";
}