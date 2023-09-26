#include "functions.h"
#include "sList.h"
#include "dList.h"
#include "csList.h"
#include "cdList.h"
#include "fifo.h"
#include "stack.h"
#include "queue.h"
#include "atomicBool.h"

void sDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Singly linked list demo started.\n";
	sList slist;
	int result;
	int position;
	int data;
	int nodeCount;
	node* list = nullptr;
	node* ptr = nullptr;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "init")
		{
			list = slist.init(cmd.input1);
			result = slist.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Node count: " << nodeCount << '\n';
				slist.print(list);
			}
		}
		else if (cmd.function == "addNodeFront")
		{
			result = slist.addNodeFront(list, cmd.input1);
			if (result == 0)
			{
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
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
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
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
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
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
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeBack")
		{
			result = slist.deleteNodeBack(&list);
			if (result == 0)
			{
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
				else
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
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
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
				std::cout << "Pointer is not in list.\n\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer is null.\n\n";
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
		else if (cmd.function == "findMinReturnPos")
		{
			result = slist.findMinReturnPos(list, data, position);
			if (result == 0)
			{
				std::cout << "List minimum " << data << " in position " << position << ".\n";
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "findMinReturnPtr")
		{
			result = slist.findMinReturnPtr(list, data, ptr);
			if (result == 0)
			{
				std::cout << "List minimum " << data << " in pointer " << ptr << ".\n";
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "findMaxReturnPos")
		{
			result = slist.findMaxReturnPos(list, data, position);
			if (result == 0)
			{
				std::cout << "List maximum " << data << " in position " << position << ".\n";
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "findMaxReturnPtr")
		{
			result = slist.findMaxReturnPtr(list, data, ptr);
			if (result == 0)
			{
				std::cout << "List maximum " << data << " in pointer " << ptr << ".\n";
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "moveToFrontByPos")
		{
			result = slist.moveToFrontByPos(&list, cmd.input1);
			if (result == 0)
			{
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Position is not in list.\n";
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

			result = slist.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Node count: " << nodeCount << '\n';
				slist.print(list);
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "reverse")
		{
			result = slist.reverse(&list);
			if (result == 0)
			{
				result = slist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					slist.print(list);
				}
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodes")
		{
			for (int i = 0; i < 9; i++)
			{
				result = slist.addNodeBack(list, pow(i, 5));
				if (result == 1)
				{
					std::cout << "List is empty.\n";
					break;
				}
			}
			result = slist.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Node count: " << nodeCount << '\n';
				slist.print(list);
			}
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
		else if (cmd.function == "deleteNodeFront")
		{
			result = dlist.deleteNodeFront(&list);
			if (result == 0)
			{
				result = dlist.size(list, nodeCount);
				if(result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					dlist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeBack")
		{
			result = dlist.deleteNodeBack(&list);
			if (result == 0)
			{
				result = dlist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					dlist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeByPos")
		{
			result = dlist.deleteNodeByPos(&list, cmd.input1);
			if (result == 0)
			{
				result = dlist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					dlist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
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
		else if (cmd.function == "updateDataByPos")
		{
			result = dlist.updateDataByPos(list, cmd.input1, cmd.input2);
			if (result == 0)
			{
				std::cout << "List updated.\n";
				dlist.print(list);
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
		else if (cmd.function == "findDataReturnPos")
		{
			result = dlist.findDataReturnPos(list, cmd.input1, cmd.output);
			if (result == 0)
			{
				std::cout << "Data '" << cmd.input1 << "' found in position " << cmd.output << ".\n";
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Data not found in list.\n";
			}
		}
		else if (cmd.function == "findDataReturnPtr")
		{
			result = dlist.findDataReturnPtr(list, cmd.input1, ptr);
			if (result == 0)
			{
				std::cout << "Data '" << cmd.input1 << "' found in pointer " << ptr << ".\n";
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Data not found in list.\n";
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
		else if (cmd.function == "clearPtr")
		{
			ptr = NULL;
			std::cout << "Pointer cleared.\n";
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
	int position;
	int data;
	int nodeCount;
	node* list = nullptr;
	node* ptr = nullptr;


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
			result = cslist.addNodeFront(list, cmd.input1);
			if (result == 0)
			{
				result = cslist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cslist.print(list);
				}
			}
			else
			{
				std::cout << "List is empty.\n\n";
			}
		}
		else if (cmd.function == "addNodeBack")
		{
			result = cslist.addNodeBack(list, cmd.input1);
			if (result == 0)
			{
				result = cslist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cslist.print(list);
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeFront")
		{
			result = cslist.deleteNodeFront(&list);
			if (result == 0)
			{
				result = cslist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cslist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeBack")
		{
			result = cslist.deleteNodeBack(&list);
			if (result == 0)
			{
				result = cslist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cslist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeByPos")
		{
			result = cslist.deleteNodeByPos(&list, cmd.input1);
			if (result == 0)
			{
				result = cslist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cslist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
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
		else if (cmd.function == "deleteNodeByPtr")
		{
			result = cslist.deleteNodeByPtr(&list, ptr);
			if (result == 0)
			{
				result = cslist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cslist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n\n";
			}
			else if (result == -1)
			{
				std::cout << "Pointer is not in list.\n\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer is null.\n\n";
			}
		}
		else if (cmd.function == "returnDataByPos")
		{
			result = cslist.returnDataByPos(list, data, cmd.input1);
			if (result == 0)
			{
				std::cout << "Data in position " << cmd.input1 << ": " << data << '\n';
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
		else if (cmd.function == "returnPtrByPos")
		{
			result = cslist.returnPtrByPos(list, cmd.input1, ptr);
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
				std::cout << "Positon is not in list.\n";
			}
		}
		else if (cmd.function == "returnPosByPtr")
		{
			result = cslist.returnPosByPtr(list, cmd.output, ptr);
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
				std::cout << "Pointer is not in list.\n\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer is null.\n\n";
			}
		}
		else if (cmd.function == "returnDataByPos")
		{
			result = cslist.returnDataByPos(list, cmd.output, cmd.input1);
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
		else if (cmd.function == "updateDataByPos")
		{
			result = cslist.updateDataByPos(list, cmd.input1, cmd.input2);
			if (result == 0)
			{
				std::cout << "List updated.\n";
				cslist.print(list);
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
		else if (cmd.function == "clear")
		{
			result = cslist.clear(&list);
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
			result = cslist.size(list, nodeCount);
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

			result = cslist.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Node count: " << nodeCount << '\n';
				cslist.print(list);
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "reverse")
		{
			result = cslist.reverse(&list);
			if (result == 0)
			{
				result = cslist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cslist.print(list);
				}
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodes")
		{
			for (int i = 0; i < 9; i++)
			{
				result = cslist.addNodeBack(list, pow(i, 5));
				if (result == 1)
				{
					std::cout << "List is empty.\n";
					break;
				}
			}
			result = cslist.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Node count: " << nodeCount << '\n';
				cslist.print(list);
			}
		}
		else if (cmd.function == "clearPtr")
		{
			ptr = nullptr;
			std::cout << "Pointer cleared.\n";
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Circular singly linked list demo stopped.\n";
}

void cdDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Circular doubly linked list demo started.\n";
	cdList cdlist;
	int result;
	int nodeCount;
	dNode* list = nullptr;
	dNode* ptr = nullptr;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "init")
		{
			list = cdlist.init(cmd.input1);
			cdlist.size(list, nodeCount);
			std::cout << "Node count: " << nodeCount << '\n';
			cdlist.print(list);
		}
		else if (cmd.function == "addNodeFront")
		{
			result = cdlist.addNodeFront(list, cmd.input1);
			if (result == 0)
			{
				cdlist.size(list, nodeCount);
				std::cout << "Node count: " << nodeCount << '\n';
				cdlist.print(list);
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodeBack")
		{
			result = cdlist.addNodeBack(list, cmd.input1);
			if (result == 0)
			{
				cdlist.size(list, nodeCount);
				std::cout << "Node count: " << nodeCount << '\n';
				cdlist.print(list);
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "addNodeByPos")
		{
			result = cdlist.addNodeByPos(list, cmd.input1, cmd.input2);
			if (result == 0)
			{
				cdlist.size(list, nodeCount);
				std::cout << "Node count: " << nodeCount << '\n';
				cdlist.print(list);
			}
			else if(result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				std::cout << "Postition is out of bounds.\n";
			}
		}
		else if (cmd.function == "deleteNodeFront")
		{
			result = cdlist.deleteNodeFront(&list);
			if (result == 0)
			{
				result = cdlist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cdlist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeBack")
		{
			result = cdlist.deleteNodeBack(&list);
			if (result == 0)
			{
				result = cdlist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cdlist.print(list);
				}
				else
				{
					std::cout << "List is empty.\n";
				}			
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "deleteNodeByPos")
		{
			result = cdlist.deleteNodeByPos(&list, cmd.input1);
			if (result == 0)
			{
				result = cdlist.size(list, nodeCount);
				if (result == 0)
				{
					std::cout << "Node count: " << nodeCount << '\n';
					cdlist.print(list);
				}
				else if (result == 1)
				{
					std::cout << "List is empty.\n";
				}
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n\n";
			}
			else if (result == -1)
			{
				std::cout << "Postition is out of bounds.\n";
			}
		}
		else if (cmd.function == "returnPtrByPos")
		{
			result = cdlist.returnPtrByPos(list, cmd.input1, ptr);
			if (result == 0)
			{
				std::cout << "Pointer to position " << cmd.input1 << ": " << ptr << '\n';
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n\n";
			}
			else if (result == -1)
			{
				std::cout << "Postition is out of bounds.\n";
			}
		}
		else if (cmd.function == "returnPosByPtr")
		{
			result = cdlist.returnPosByPtr(list, cmd.output, ptr);
			if (result == 0)
			{
				std::cout << "Pointer " << ptr << " is in position " << cmd.output << ".\n";
			}
			else if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == -1)
			{
				
				std::cout << "Pointer not in list.\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer is null.\n";
			}
		}
		else if (cmd.function == "returnDataByPos")
		{
			result = cdlist.returnDataByPos(list, cmd.output, cmd.input1);
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
				std::cout << "Postition is out of bounds.\n";
			}
		}
		else if (cmd.function == "returnDataByPtr")
		{
			result = cdlist.returnDataByPtr(list, cmd.output, ptr);
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
				std::cout << "Pointer is not in list.\n\n";
			}
			else if (result == -2)
			{
				std::cout << "Pointer is null.\n\n";
			}
		}
		else if (cmd.function == "clear")
		{
			result = cdlist.clear(&list);
			if (result == 0)
			{
				std::cout << "List is empty.\n";
			}
			else
			{
				std::cout << "List was already empty.\n";
			}
		}
		else if (cmd.function == "isEmpty")
		{
			result = cdlist.isEmpty(list);
			if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else
			{
				std::cout << "List is not empty.\n";
			}
		}
		else if (cmd.function == "size")
		{
			result = cdlist.size(list, nodeCount);
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
			result = cdlist.print(list);
			if (result != 0)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "printReverse")
		{
			result = cdlist.printReverse(list);
			if (result != 0)
			{
				std::cout << "List is empty.\n";
			}
			}
		else if (cmd.function == "addNodes")
		{
			if (list != nullptr)
			{
				for (int i = 0; i < 9; i++)
				{
					cdlist.addNodeBack(list, i * i * i * i);
				}
				cdlist.size(list, nodeCount);
				std::cout << "Node count: " << nodeCount << '\n';
				cdlist.print(list);
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "clearPtr")
		{
			ptr = nullptr;
			std::cout << "Pointer cleared.\n";
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Circular doubly linked list demo stopped.\n";
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
	int nodeCount;
	node* list = NULL;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "push")
		{
			stack.push(&list, cmd.input1);
			stack.print(list);
		}
		else if (cmd.function == "pop")
		{
			result = stack.pop(&list);
			if (result == 0)
			{
				result = stack.print(list);
				if (result == 1)
				{
					std::cout << "Stack is empty.\n";
				}
			}
			else if(result == 1)
			{
				std::cout << "Stack is empty.\n";
			}
		}
		else if (cmd.function == "top")
		{
			result = stack.top(list, cmd.output);
			if (result == 0)
			{
				std::cout << "Top node: " << cmd.output << '\n';
			}
			else if (result == 1)
			{
				std::cout << "Stack is empty.\n";
			}
		}
		else if (cmd.function == "clear")
		{
			result = stack.clear(&list);
			if (result == 0)
			{
				std::cout << "Stack cleared.\n";
			}
			else
			{
				std::cout << "Stack is empty.\n";
			}
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
			result = stack.size(list, nodeCount);
			if (result == 0)
			{
				std::cout << "Stack size: " << nodeCount << '\n';
			}
			else if (result == 1)
			{
				std::cout << "Stack is empty.\n";
			}
		}
		else if (cmd.function == "print")
		{
			result = stack.print(list);
			if (result == 1)
			{
				std::cout << "Stack is empty.\n";
			}
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Stack dmeo stopped.\n";
}

void queueDemo(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Queue demo started.\n";
	queue q;
	int result;
	int nodeCount;
	dNode* list = nullptr;

	std::unique_lock<std::mutex> lk(m);
	cv.notify_one();
	while (status)
	{
		cv.wait(lk);
		std::cout << '\n';
		if (cmd.function == "push")
		{
			result = q.push(list, cmd.input1);
			q.print(list);
		}
		else if (cmd.function == "pop")
		{
			result = q.pop(&list);
			if (result == 0)
			{
				result = q.print(list);
				if (result != 0)
				{
					std::cout << "List is empty.\n";
				}
			}
			else if(result == 1)
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "front")
		{
			result = q.front(list, cmd.output);
			if (result == 0)
			{
				std::cout << "First element in queue: " << cmd.output << '\n';
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "back")
		{
			result = q.back(list, cmd.output);
			if (result == 0)
			{
				std::cout << "Last element in queue: " << cmd.output << '\n';
			}
			else
			{
				std::cout << "List is empty.\n";
			}
		}
		else if (cmd.function == "clear")
		{
			result = q.clear(&list);
			if (result == 0)
			{
				std::cout << "List is empty.\n";
			}
			else if (result == 1)
			{
				std::cout << "List was already empty.\n";
			}
		}
		else if (cmd.function == "isEmpty")
		{
			result = q.isEmpty(list);
			if (result == 1)
			{
				std::cout << "List is empty.\n";
			}
			else
			{
				std::cout << "List is not empty.\n";
			}
		}
		else if (cmd.function == "size")
		{
			result = q.size(list, nodeCount);
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
			result = q.print(list);
			if (result != 0)
			{
				std::cout << "List is empty.\n";
			}
		}
		cv.notify_one();
	}
	cv.notify_one();
	std::cout << "Queue demo stopped.\n";
}