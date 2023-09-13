#include "functions.h"
#include "sList.h"
#include "csList.h"
#include "fifo.h"
#include "stack.h"
#include "atomicBool.h"

void sFunc(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Singly linked list thread started.\n";
	sList slist;
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
			list = slist.init(cmd.data);
			slist.print(list);
		}
		else if (cmd.function == "addNodeBack")
		{
			slist.addNodeBack(list, cmd.data);
			slist.print(list);
		}
		else if (cmd.function == "clear")
		{
			slist.clear(&list);
			slist.print(list);
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
			std::cout << "Node count: " << slist.size(list) << '\n';
			slist.print(list);
		}
		else if (cmd.function == "print")
		{
			slist.print(list);
		}
		cv.notify_one();
	}
	cv.notify_all();
	std::cout << "Singly linked list thread stopped.\n";
}

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

void stackFunc(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	std::cout << "Stack thread started.\n";
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
			list = stack.init(cmd.data);
			stack.print(list);
		}
		else if (cmd.function == "push")
		{
			stack.push(list, cmd.data);
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
	std::cout << "Stack thread stopped.\n";
}