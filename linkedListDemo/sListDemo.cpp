#include "sListDemo.h"

void singlyLinkedListDemo()
{
	std::cout << "\n\nSingly Linked List Demo\n\n";
	// initialize singly listed list.
	std::cout << "Initialize singly listed list.\n";
	sList sList;
	node* list = sList.initList(1);

	// add eight new nodes to the end of the list.
	for (int i = 2; i < 10; i++)
	{
		sList.addNodeBack(list, i * i);
	}
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// add a new node to the front of the list.
	sList.addNodeFront(list, 1234);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// add another node to the end of the list.
	sList.addNodeBack(list, 2345);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// add a node in the sixth position of the list.
	sList.addNode(list, 4321, 5);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// return data for element 5.
	int elementPos = 5;
	std::cout << "element " << elementPos << ": " << sList.accessNode(list, elementPos) << "\n\n";

	// update data for element 5.
	int result = sList.updateNodeData(list, -1234, 5);
	if (result != 0)
	{
		std::cout << "Update linked list failed.\n\n";
	}
	else
	{
		std::cout << "Linked list updated.\n\n";
	}
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// find element with "16" for data.
	std::cout << "Find 16: element " << sList.find(list, 16) << "\n\n";

	// delete element 5.
	sList.deleteNode(list, 0);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// check if list is empty.
	result = sList.empty(list);
	if (result != 0)
	{
		std::cout << "List is not empty.\n\n";
	}
	else
	{
		std::cout << "List is empty.\n\n";
	}

	// delete nodes after the 5th element.
	sList.deleteAfter(list, 5);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// delete the first node.
	sList.deleteNodeFront(&list);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// clear the list.
	sList.clear(&list);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);
}