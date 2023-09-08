#include "stackDemo.h"

void stackDemo()
{
	std::cout << "\n\nStack Demo\n\n";
	// initialize singly listed list.
	stack stack;
	node* list = stack.init(1);

	// add eight new nodes to the stack.
	for (int i = 2; i < 10; i++)
	{
		stack.push(list, i * i);
	}
	stack.print(list);

	// pop top node from stack.
	std::cout << "Popped from stack: " << stack.pop(&list) << "\n\n";
	stack.print(list);

	// pop top another node from stack.
	std::cout << "Popped from stack: " << stack.pop(&list) << "\n\n";
	stack.print(list);
}