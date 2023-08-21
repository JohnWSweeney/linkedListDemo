#include "demos.h"

void singlyLinkedListDemo()
{
	std::cout << "\n\nSingly Linked List Demo\n\n";
	// initialize singly listed list.
	sNode *list = new sNode();
	sList sList;

	// add five new nodes to the end of the list.
	for (int i = 1; i < 6; i++)
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
}

void doublyLinkedListDemo()
{
	std::cout << "\n\nDoubly Linked List Demo\n\n";
	// initialize doubly linked list.
	dNode *list = new dNode();
	dList dList;

	// add five new nodes to the end of the list.
	for (int i = 1; i < 6; i++)
	{
		dList.addNodeBack(list, i * i);
	}
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list, false);

	// add a new node to the front of the list.
	dList.addNodeFront(list, 321);
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list, false);
	
	// add another node to the end of the list.
	dList.addNodeBack(list, 123);
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list, false);

	// return data for element 3.
	int elementPos = 3;
	std::cout << "element " << elementPos << ": " << dList.accessNode(list, elementPos) << "\n\n";

	// update data for element 3.
	int result = dList.updateNodeData(list, 345, elementPos);
	if (result != 0)
	{
		std::cout << "Update linked list failed.\n\n";
	}
	else
	{
		std::cout << "Linked list updated.\n\n";
	}
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list, true);
}