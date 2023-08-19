#include <iostream>
#include "random.h"
#include "sList.h"
#include "dList.h"
#include <chrono>
#include <thread>

void singleTester()
{
	sNode *list = new sNode();

	sList sList;
	for (int i = 1; i < 6; i++)
	{
		sList.addNodeBack(list, i * i);
	}

	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	sList.addNodeFront(list, 1234);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	sList.addNodeBack(list, 2345);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	sList.addNode(list, 4321, 5);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	int elementPos = 0;
	std::cout << "element " << elementPos << ": " << sList.accessNode(list, elementPos) << "\n\n";

	sList.updateNodeData(list, -1, 0);
	std::cout << "linked list size: " << sList.size(list) << '\n';
	sList.printList(list, false);

	std::cout << "Find 4321: element " << sList.find(list, 4321) << "\n\n";

	sList.printList(list, true);
}

int main()
{
	std::cout << "linkedListDemo v0.3.0\n\n";

	//singleTester();

	dNode *list = new dNode();
	dList dList;

	for (int i = 1; i < 6; i++)
	{
		dList.addNodeBack(list, i);
	}

	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list);

	dList.addNodeFront(list, 666);
	std::cout << "linked list size: " << dList.size(list) << '\n';
	dList.printList(list);
}