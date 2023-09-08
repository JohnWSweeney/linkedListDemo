#include "dListDemo.h"

void doublyLinkedListDemo()
{
	std::cout << "\n\nDoubly Linked List Demo\n\n";
	// initialize doubly linked list.
	dList dList;
	dNode* list = dList.initList(1);

	// add eight new nodes to the end of the list.
	for (int i = 2; i < 10; i++)
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

	// delete element 3.
	dList.deleteNode(list, elementPos);
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list, true);

	// delete nodes after the 5th element.
	dList.deleteAfter(list, elementPos);
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list, true);

	// clear the list.
	dList.clear(list);
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list, true);
}