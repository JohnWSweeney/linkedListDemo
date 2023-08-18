#include <iostream>
#include "random.h"
#include "sll.h"

int main()
{
	std::cout << "linkedListDemo v0.2.0\n\n";

	node *list = new node();

	sll sll;
	for (int i = 1; i < 6; i++)
	{
		sll.addNodeBack(list, i*i);
	}

	std::cout << "linked list size: " << sll.size(list) << '\n';
	sll.printList(list, false);

	sll.addNodeFront(list, 1234);
	std::cout << "linked list size: " << sll.size(list) << '\n';
	sll.printList(list, false);

	sll.addNodeBack(list, 2345);
	std::cout << "linked list size: " << sll.size(list) << '\n';
	sll.printList(list, false);

	sll.addNode(list, 4321, 5);
	std::cout << "linked list size: " << sll.size(list) << '\n';
	sll.printList(list, false);

	int elementPos = 0;
	std::cout << "element " << elementPos << ": " << sll.accessNode(list, elementPos) << '\n';

	sll.updateNodeData(list, -1, 0);
	std::cout << "linked list size: " << sll.size(list) << '\n';
	sll.printList(list, false);

	sll.printList(list, true);
}