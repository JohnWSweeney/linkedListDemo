# linkedListDemo

A console app exploring linked lists and their applications. The app includes classes for singly, doubly, circular singly, and circular doubly linked lists. Linked list applications include classes for stacks, queues, and FIFOs. The Windows executable is compiled with C++17.

## Functions
The app opens a console window on startup. Enter the *command* keywords separated by a space. Commands are case-sensitive. 

## Linked Lists
Four types of listed links are explored: singly, doubly, circular singly (csList), and circular doubly (cdList). Each list type has its own class and interactive demo to its class functions. Each node in the list stores an integer as `data` and a pointer to the next node in the list as `next`. Doubly linked list nodes have a second pointer `prev` that points to the previous node in the list.

To start or stop a linked list demo, enter:
> *start listType*

> *stop*

where *listType* is `sList` is for singly linked list, `dList` is for doubly linked list, `csList` is for circular singly linked list, and `cdList` is for circular doubly linked list.

First, you'll need to initialize the list with first piece of data by entering:
> *init integer*

You can then add new nodes to the beginning or end of the list with the "addNodeFront" and "addNodeBack" functions, respectively:
> *addNodeFront integer*

> *addNodeBack integer*

Similarly, the first and last nodes can be removed by:
> *deleteNodeFront*

> *deleteNodeBack*

You can remove all nodes in the list by entering:
> *clear*

You'll have to reinitialize the list with `init` if you want to add more nodes to the list.

To check if the list is empty, enter:
> *isEmpty*

To find the list's node count, enter:
> *size*

To view the list's current contents, enter:
> *print*

To reverse the order of nodes in the list, enter:
> *reverse*

## Linked List Applications
The app includes three interactive linked lists applications, including stacks and queues. To start or stop an application demo, enter:
> *start listType*

> *stop*

where *listType* is `stack`, `queue`, or `fifo`.

### Stack
The stack class is implemented with singly linked lists and modeled on the STL [std::stack](https://en.cppreference.com/w/cpp/container/stack) class. Functions include push, pop, top, clear, isEmpty, size, and print functions. 

To add a new node to the top of the stack, enter:
> *push integer*

To access the top node's data, enter:
> *top*

To remove the top node, enter:
> *pop*

The `clear`, `isEmpty`, `size`, and `print` functions work identically to the those in the list classes.

### Queue
The queue class is implemented with circular doubly linked lists and modeled on the STL [std::queue](https://en.cppreference.com/w/cpp/container/queue) class. Functions include push, pop, front, back, clear, isEmpty, size, and print functions. 

To add a new node to the back of the queue, enter:
> *push integer*

To remove the node at the front of the queue, enter:
> *pop*

To return the front or back nodes' data, enter:
> *front*

> *back*

The `clear`, `isEmpty`, `size`, and `print` functions work identically to the those in the list and stack classes.

## Future Updates
- ?

## Download
[linkedListDemo v1.5.6](https://github.com/JohnWSweeney/linkedListDemo/releases/download/v1.5.6/linkedListDemo_v1_5_6.exe) [79 kB]

## ChangeLog
v1.5.9
- Updated dList class and demo.
	- Added addNodeByPos, deleteNodeByPtr, returnDataByPtr, updateDataByPtr, findMinReturnPos, findMinReturnPtr, findMaxReturnPos, findMaxReturnPtr, and reverse functions.
	- Updated deleteNodeByPos function.

v1.5.8
- Updated fifo class and demo.
	- Added config function to set FIFO word depth.
	- Updated all functions to check FIFO configuration and determine FIFO state (full, almost full, overflow, empty, almost empty, and underflow), where appropriate.

v1.5.7
- Updated fifo class and demo.
	- Merged init function with write.
	- Updated all functions to return C-style error codes.
	- Replaced all instances of "NULL" with "nullptr".
	- Renamed functions following Xilinx common clock FIFO conventions. where appropriate.

v1.5.6
- Updated csList class and demo.
	- Updated deleteNodeFront, deleteNodeBack, deleteNodeByPtr, returnPtrByPos, returnPosByPtr, returnDataByPos, updateDataByPos, size, isEmpty, and print functions.
	- Added deleteNodeByPos, clear, reverse, and addNodes functions.
	- Replaced all instances of "NULL" with "nullptr".

v1.5.5
- Updated sList class and demo.
	- Added findMinReturnPtr, findMaxReturnPtr, and reverse functions.

v1.5.4
- Updated sList class and demo.
	- Added findMinReturnPos, findMaxReturnPos, and moveToFrontByPos functions.
	- Replaced all instances of "NULL" with "nullptr".
	- Fixed miscellaneous bugs and housekeeping.

v1.5.3
- Updated stack class and demo.
	- Merged init function with push, added top function.
	- Updated all functions to return C-style error codes.
	- Replaced all instances of "NULL" with "nullptr".

v1.5.2
- Updated dList class and demo.
	- Added deleteNodeFront, deleteNodeBack, and deleteNodeByPos functions.
	- Replaced all instances of "NULL" with "nullptr".

v1.5.1
- Updated cdList class and cdDemo.
	- Added addNodeByPos, returnDataByPos, returnDataByPtr, printReverse, and clearPtr functions.

v1.5.0
- Added queue class and interactive demo function, updated commands, functions, threads headers/cpps accordingly. 
	- Added push, pop, front, back, clear, isEmpty, size, and print functions.

v1.4.6
- Updated cdList class and cdDemo.
	- Added deleteNodeFront, deleteNodeBack, and deleteNodeByPos functions.
	- Updated size function to zero nodeCount when list is null.

v1.4.5
- Updated cdList class and cdDemo.
	- Added returnPtrByPos, returnPosByPtr, clear, and isEmpty functions.

v1.4.4
- Added interactive circular doubly linked list class demo, updated commands, functions, threads headers/cpps accordingly. 
- Began refactoring cdList class: removed all functions, adding revised versions.
	- Added init, addNodeFront, addNodeBack, size, print, and addNodes functions.

v1.4.3
- Updated dList class, demo.
	- Added findDataReturnPtr function.

v1.4.2
- Updated dList class, demo.
	- Added updateDataByPos, findDataReturnPos, and clearPtr functions.

v1.4.1
- Updated dList class, demo.
	- Added returnPtrByPos, returnPosByPtr, returnDataByPos, and addNodes functions.

v1.4.0
- Renamed class demo functions in functions header/cpp to from "-Func" to "-Demo".
- Added interactive doubly linked list class demo, updated commands, functions, threads headers/cpps accordingly. 
- Began refactoring dList class: removed all functions, adding revised versions.
	- Added init, addNodeFront, addNodeBack, clear, isEmpty, size, and print functions.

v1.3.3
- Updated addNodeBack, deleteNodeFront, clear, size, and print functions in sList class to return int error codes.

v1.3.2
- Added returnPosByPtr, returnDataByPos, and returnDataByPtr functions to sList class.

v1.3.1
- Added updateDataByPos, updateDataByPtr, findDataReturnPos, and findDataReturnPtr functions to sList class.

v1.3.0
- Renamed int data in cmd struct to input1, added int input2, int output.
- Added addNodeByPos function to sList class.
- Updated affected functions in commands, functions cpps.

v1.2.1
- Added addNodeFront, addNodes, deleteNodeBack, returnPtrByPos, deleteNodeByPtr functions to sList class, sListFuncsInts in commands cpp, sFunc in functions cpp.

v1.2.0
- Added clear, isEmpty, size functions to stack class.
- Added threaded control of stack class.

v1.1.0
- Updated singly linked list class functions and names: init, isEmpty, and print.
- Added threaded control of singly linked list class.

v1.0.2
- Updated command struct "listType" and subsequence sorting functions to use class name, i.e. "csList" vs "cs" for circular singly linked list classes and functions.

v1.0.1
- Updated startMenu, command header/cpp functions.

v1.0.0
- Removed demo functions in favor of interactive function threads.
	- Added start, commands, threads, functions, and atomicBool headers/cpps.
	- Added threaded control of circular singly linked list and FIFO classes.
- Updated fifo class functions with list NULL catch statements.

v0.16.0
- Moved each class demo function in demos.h/cpp to its own .h/cpp files.
- Updated circular singly linked list class csList.h/cpp.
	- Added deleteNodeFront, deleteNodeBack, deleteNodeByPtr, returnPtrByPos, and returnPosByPtr functions.
	- Renamed accessNode to returnDataByPos, updateNode to updateNodeByPos.
- Updated circularSinglyLinkedListDemo in csListDemo.h/cpp. with new functions.

v0.15.0
- Updated circular doubly linked list class cdList.h/cpp.
	- Added addNodeFront, deleteNodeFront, returnPtrByPos, size, and printReverse functions.
- Updated circularDoublyLinkedListDemo in demos.h/cpp. with new functions.

v0.14.0
- Added circular singly linked list class csList.h/cpp.
	- Added init, addNodeFront, addNodeBack, accessNode, updateNode, size, isEmpty, and print functions.
- Added circularSinglyLinkedListDemo to demos.h/cpp.
- Changed circular singly linked list class name to cdList.h/cpp.

v0.13.0
- Added circular doubly linked list class cdList.h/cpp.
	- Added init, addNodeBack, deleteNodeBack, isEmpty, and print functions.
- Added circularDoublyLinkedListDemo to demos.h/cpp.

v0.12.0
- Updated singly linked list class.
	- Added empty, removeNodeFront functions.
	- Updated clear, printList, size functions.

v0.11.0
- Added list initialization functions to each class.
- Updated demo functions with their respective list initialization functions.

v0.10.0
- Added stack class stack.h/cpp.
	- Added push, pop, and print functions.
- Added stackDemo to demos.h/cpp.

v0.9.0
- Added nodes.h
	- Includes singly and doubly linked list node definitions.

v0.8.0
- Added FIFO (first-in-first-out) class, fifo.h/cpp.
	- Includes write, read, size, clear, and print functions.
	- Implemented as singly linked list.
- Added fifoDemo function to demos.h/cpp.

v0.7.0
- Added deleteAfter, clear functions to doubly linked list class.

v0.6.0
- Added deleteAfter, clear functions to singly linked list class.

v0.5.0
- Added deleteNode functions to singly/doubly linked list classes.
- Updated doubly linked list class printList function to display "prev" pointer.

v0.4.0
- Added demos.h/cpp demonstrating each class's functions.
- Updated doubly linked list class dList.h/cpp.
	- Added accessNode, updateNodeData, find functions.
	- Updated printList with boolean option to print node details.
- Updated singly linked list class sList.h/cpp.
	- Updated updateNodeData to return error code.

v0.3.0
- Updated singly linked list class.
	- Renamed all instances of "sll" to "sList", node struct to "sNode".
	- Added find function.
- Added doubly linked list class dList.h/cpp.
	- Added addNodeFront, addNodeBack, size, and printList functions.

v0.2.0
- Updated singly linked list class, sll.h/cpp.
	- Added accessNode, addNode, addNodeFront, updateNodeData functions.
	- Updated printList with boolean option to print node details.
	- Renamed addNodeEnd to addNodeBack.
	- Removed temporary node from AddNodeEnd, size functions.

v0.1.0
- Added addNodeEnd, size functions to singly linked list class, sll.h/cpp.
- Added README.

v0.0.0
- Initial commit.
- Started singly linked list class, sll.h/cpp.
	- Added printList function.