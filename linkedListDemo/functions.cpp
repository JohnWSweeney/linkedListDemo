#include "functions.h"
#include "csList.h"
#include "fifo.h"
#include "atomicBool.h"

void csFunc(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Circular singly linked list thread started.\n";
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
			list = cslist.init(cmd.data);
			cslist.print(list);
		}
		else if (cmd.function == "addNodeFront")
		{
			cslist.addNodeFront(list, cmd.data);
			cslist.print(list);
		}
		else if (cmd.function == "addNodeBack")
		{
			cslist.addNodeBack(list, cmd.data);
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
	std::cout << "Circular singly linked list thread stopped.\n";
}

void fifoFunc(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "FIFO thread started.\n";
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
			list = fifo.init(cmd.data);
			fifo.print(list);
		}
		else if (cmd.function == "write")
		{
			fifo.write(list, cmd.data);
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
	std::cout << "FIFO thread stopped.\n";
}