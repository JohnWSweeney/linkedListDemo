#include "sListDemo.h"
#include "dListDemo.h"
#include "fifoDemo.h"
#include "stackDemo.h"
#include "csListDemo.h"
#include "cdListDemo.h"

int main()
{
	std::cout << "linkedListDemo v0.16.0\n\n";

	singlyLinkedListDemo();
	doublyLinkedListDemo();
	fifoDemo();
	stackDemo();
	circularSinglyLinkedListDemo();
	circularDoublyLinkedListDemo();
}