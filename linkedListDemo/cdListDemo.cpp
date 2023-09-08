#include "cdListDemo.h"

void circularDoublyLinkedListDemo()
{
	std::cout << "\n\Circular Doubly Linked List Demo\n\n";
	// initialize doubly linked list.
	cdList cdList;
	dNode* list = cdList.init(3141);

	// add eight nodes to the end of the list;
	for (int i = 0; i < 9; i++)
	{
		cdList.addNodeBack(list, i * i * i);
	}
	std::cout << "Node count: " << cdList.size(list) << '\n';
	cdList.print(list);

	// check if the list is empty.
	int result = cdList.isEmpty(list);
	if (result == 1)
	{
		std::cout << "The list is empty.\n\n";
	}
	else
	{
		std::cout << "The list is not empty.\n\n";
	}

	// add node to front of the list.
	cdList.addNodeFront(list, 321);
	std::cout << "Node count: " << cdList.size(list) << '\n';
	cdList.print(list);

	// delete the front node.
	cdList.deleteNodeFront(&list);
	std::cout << "Node count: " << cdList.size(list) << '\n';
	cdList.print(list);

	// delete node at the end of the list.
	cdList.deleteNodeBack(list);
	std::cout << "Node count: " << cdList.size(list) << '\n';
	cdList.print(list);

	// print the list in reverse order.
	cdList.printReverse(list);

	// return pointer to the node in the requested position in the list.
	int position = 5;
	dNode* ptr = NULL;
	ptr = cdList.returnPtrByPos(list, position);
	std::cout << "ptr to node " << position << ":\t" << ptr << '\n';
}