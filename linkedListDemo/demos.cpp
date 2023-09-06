#include "demos.h"
#include "nodes.h"
#include "sList.h"
#include "dList.h"
#include "fifo.h"
#include "stack.h"
#include "csList.h"
#include "cdList.h"

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

void fifoDemo()
{
	std::cout << "\n\nFIFO Demo\n\n";
	// initialize singly listed list.
	fifo fifo;
	node* list = fifo.init(1);

	// write eight "words" to the FIFO.
	for (int i = 2; i < 10; i++)
	{
		fifo.write(list, i * i);
	}
	std::cout << "FIFO size: " << fifo.size(list) << '\n';
	fifo.print(list);
	std::cout << '\n';

	// read one word from the FIFO.
	std::cout << "FIFO data out: " << fifo.read(list) << '\n';
	std::cout << "FIFO size: " << fifo.size(list) << '\n';
	fifo.print(list);
	std::cout << '\n';

	// read four words from the FIFO.
	for (int i = 0; i < 4; i++)
	{
		std::cout << "FIFO data out: " << fifo.read(list) << '\n';
	}

	std::cout << "FIFO size: " << fifo.size(list) << '\n';
	fifo.print(list);
	std::cout << '\n';

	// clear the FIFO.
	fifo.clear(list);
	std::cout << "FIFO size: " << fifo.size(list) << '\n';
	fifo.print(list);
	std::cout << '\n';
}

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

	// return data for element 5.
	int element = 5;
	std::cout << "List element " << element << ": " << csList.accessNode(list, element) << '\n';

	// update data for element 5.
	int newData = 101010;
	std::cout << "Update list element " << element << " data with " << newData << csList.updateNode(list, element, newData) << '\n';
	std::cout << "Node count: " << csList.size(list) << '\n';
	csList.print(list);
}

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