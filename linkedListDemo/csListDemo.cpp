#include "csListDemo.h"

void circularSinglyLinkedListDemo()
{
	std::cout << "\n\nCircular Singly Linked List Demo\n\n";
	// initialize singly listed list.
	csList csList;
	node* list = csList.init(4321);

	// add eight new nodes to the end of the list.
	for (int i = 0; i < 9; i++)
	{
		csList.addNodeBack(list, i * i * i);
	}
	std::cout << "Node count: " << csList.size(list) << '\n';
	csList.print(list);

	// check if list is empty.
	int result = csList.isEmpty(list);
	if (result != 0)
	{
		std::cout << "List is empty.\n";
	}
	else
	{
		std::cout << "List is not empty.\n";
	}
	std::cout << '\n';

	// add a new node to the front of the list.
	csList.addNodeFront(list, 1234);
	std::cout << "Node count: " << csList.size(list) << '\n';
	csList.print(list);

	// return data for position 5.
	int position = 5;
	std::cout << "List position " << position << ": " << csList.returnDataByPos(list, position) << '\n';

	// return pointer to position 5.
	node* ptr5 = NULL;
	ptr5 = csList.returnPtrByPos(list, position);
	std::cout << "Pointer ptr5 to list position 5: " << ptr5 << '\n';
	
	// update data for position 5.
	int newData = 101010;
	std::cout << "Update list position " << position << " data with " << newData << csList.updateNodeByPos(list, position, newData) << "\n\n";
	std::cout << "Node count: " << csList.size(list) << '\n';
	csList.print(list);

	// delete the first and last nodes in the list.
	csList.deleteNodeFront(list);
	csList.deleteNodeBack(list);
	std::cout << "Node count: " << csList.size(list) << '\n';
	csList.print(list);

	// return pointer to the node in list position 6 and delete the node.
	position = 6;
	node* ptr = NULL;
	ptr = csList.returnPtrByPos(list, position);
	std::cout << "List position " << position << " ptr: " << ptr << '\n';
	csList.deleteNodeByPtr(list, ptr);
	std::cout << "Node count: " << csList.size(list) << '\n';
	csList.print(list);

	// find ptr5's new position in the list.
	std::cout << "ptr5 is now position " << csList.returnPosByPtr(list, ptr5) << " in the list.\n";
}