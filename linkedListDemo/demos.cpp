#include "demos.h"
#include "nodes.h"
#include "sList.h"
#include "dList.h"
#include "fifo.h"
#include "stack.h"

void singlyLinkedListDemo()
{
	std::cout << "\n\nSingly Linked List Demo\n\n";
	// initialize singly listed list.
	node *list = new node();
	sList sList;

	// add nine new nodes to the end of the list.
	for (int i = 1; i < 10; i++)
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

	// delete nodes after the 5th element.
	sList.deleteAfter(list, 5);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	// clear the list.
	sList.clear(list);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);
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
	node* list = new node();
	fifo fifo;

	// write 8 "words" to the FIFO.
	for (int i = 1; i < 9; i++)
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
	node* top = new node();
	node* list = top;
	stack stack;

	// add nine new nodes to the stack.
	for (int i = 1; i < 10; i++)
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