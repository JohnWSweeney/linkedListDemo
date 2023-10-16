# linkedListDemo

A console app exploring linked lists and their applications. The app includes classes for singly, doubly, circular singly, and circular doubly linked lists. Linked list applications include classes for stacks, queues, and FIFOs. The Windows executable is compiled with C++17.

## Function
The app opens a console window on startup. Enter the *command* keywords separated by a space. Commands are case-sensitive. 

## Linked Lists
Four types of linked lists are explored: singly, doubly, circular singly, and circular doubly.  Each list node stores an integer as `data` and a pointer to the next node in the list as `next`. Doubly linked list nodes have a second pointer `prev` that points to the previous node in the list.

Each list type has its own class and interactive demo to test its functions, such as adding and deleting nodes and updating their data. The following functions are available in each list type's demo.

To start or stop a linked list demo, enter:
> *start listType*

> *stop*

where *listType* is `sList` is for a singly linked list, `dList` is for a doubly linked list, `csList` is for a circular singly linked list, and `cdList` is for a circular doubly linked list.

First, you'll need to initialize the list with the first piece of data by entering:
> *init integer*

You can then add new nodes to the beginning or end of the list by entering:
> *addNodeFront integer*

> *addNodeBack integer*

You can also add a default set of nodes to the list by entering:
> *addNodes*

Just for fun, you can add an indefinite number of nodes with random integers by entering:
> *addRandomNodes numInt minInt maxInt*

where `numInt` is the number of nodes you wish to add to the list and `minInt` and `maxInt` are the lower and upper bounds, respectively, from which the random integers will be selected. Random integers are generated with the STL 32-bit Mersenne Twister engine and added to the end of the list with the `addNodeBack` function. 

The first and last nodes can be removed by:
> *deleteNodeFront*

> *deleteNodeBack*

You can remove all nodes in the list by entering:
> *clear*

Note that you'll have to reinitialize the list with `init` if you want to add more nodes to the list.

To check if the list is empty, enter:
> *isEmpty*

To find the list's node count, enter:
> *size*

To view the list's full contents, enter:
> *print*

To reverse the order of nodes in the list, enter:
> *reverse*

### Functions By List Position
Each class includes functions that operate on nodes according to their list position. List positions begin at zero, so the first node position is 0, the second node position is 1, and so on.

To add a node in an existing position, enter:
> *addNodeByPos data position*

This will push the node in the requested position in the next position (one down in the list) and put the new node in its place. If the new node's requested position happens to be the final position, the list will be extended by one to hold the old node.

To delete a node by its position, enter:
> *deleteNodePos position*

To return a pointer to a node by its position, enter:
> *returnPtrByPos position*

To return the data of a node by its position, enter:
> *returnDataByPos position*

To find the position of the list's tail node, enter:
>*findTailReturnPos*

To update a specific node's data, enter:
>*updateDataByPos data position*

To find the list position of a node with specific data, enter:
>*findDataReturnPos data*

To find the positions of nodes storing the smallest and largest integers, enter:
>*findMinReturnPos*

or

>*findMaxReturnPos*

### Functions By Pointer
Each class also includes functions that operate directly on nodes by their pointers. First, you need to find the pointer to the node of interest by entering:
>*returnPtrByPos position*

where *position* is the node's list position.

To delete a node by its pointer, enter:
>*deleteNodeByPtr*

To return a node's data by its pointer, enter:
>*returnDataByPtr*

To return a pointer to the list's tail node, enter:
>*findTailReturnPtr*

To update a node's data by its pointer, enter:
>*updateDataByPtr data*

To find the pointer to a node with specific data, enter:
>*findDataReturnPtr data*

To find pointers to node's storing the smallest and largest integers, enter:
>*findMinReturnPtr*

or

>*findMaxReturnPtr*

## Linked List Applications
The app includes three interactive linked list applications, including stacks, queues, and a Xilinx FPGA FIFO simulator. To start or stop an application demo, enter:
> *start listType*

> *stop*

where *listType* is `stack`, `queue`, or `fifo`.

### Stack
The stack class is implemented with singly linked lists and based on the STL [std::stack](https://en.cppreference.com/w/cpp/container/stack) class. Functions include push, pop, top, clear, isEmpty, size, and print functions. 

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

### Xilinx FPGA FIFO Simulator
Just for fun, I simulated a Xilinx FPGA FIFO as a singly linked list. Unlike the STL queue, Xilinx FIFOs have limited capacity that is configured before synthesis. The FIFO updates its capacity status after every operation, indicating empty, almost empty (one word left), almost full (one vacancy left), full, or none of the above (i.e., filled between almost empty and almost full). Xilinx documentation also refers to FIFO entries as "words" rather than nodes. Aside from that, they work the same as STL queues. The FIFO class function names are based on Xilinx conventions.

To start or stop the FIFO demo, enter:
> *start fifo*

> *stop*

First, you'll need to configure FIFO capacity by entering:
> *config integer*

where *integer* is the number of words (nodes) the FIFO can hold. This number must be greater than zero and is currently limited to a maximum of 4096.

Next, you can write to the FIFO by entering:
> *write integer*

where *integer* is the data you wish to store. Writing to a full FIFO will return an overflow error.

The Xilinx FIFO *read* function combines the STL queue "front" and "pop" functions, returning the first word in the FIFO while also removing it. 
> *read* 

You can manually check the FIFO capacity status by entering: 
> *size*

which will also return empty, almost empty, almost full, and full messages when appropriate.

The `clear` and `print` functions work identically to the other classes.

## Future Updates
- Everytime I think I'm done, I find new and interesting functions to implement, so who knows.

## Download
[linkedListDemo v1.6.0](https://github.com/JohnWSweeney/linkedListDemo/releases/download/v1.6.0/linkedListDemo_v1_6_0.exe) [86 kB]

## ChangeLog
v1.6.13
- Updated addNodeFront functions in sList, csList, and cdList classes to preserve the original head node's pointer.

v1.6.12
- Updated csList class and demo.
	- movePosToFront and movePosToBack functions.
- Updated sList movePosToFront function and demo to fix bug when list has only one node.
- Added error codes 5 (list has only one node) and -2 (no action required).

v1.6.11
- Updated csList class and demo.
	- Added movePosUp, movePosDown functions.

v1.6.10
- Updated sList class and demo.
	 - Added movePosUp, movePtrUp, movePosDown, and movePtrDown functions.

v1.6.9
- Updated csList class and demo.
	 - Added movePtrToFront, movePtrToBack, movePtrUp, and movePtrDown functions.

v1.6.8
- Updated cdList class and demo.
	- Added deleteBeforePos, deleteBeforePtr, deleteAfterPos, and deleteAfterPtr functions.

v1.6.7
- Updated csList class and demo.
	 - Added deleteBeforePos, deleteBeforePtr, deleteAfterPos, and deleteAfterPtr functions.

v1.6.6
- Updated dList class and demo.
	- Added deleteBeforePos, deleteBeforePtr, deleteAfterPos, and deleteAfterPtr functions.

v1.6.5
- Updated sList class and demo.
	- Added deleteBeforePos, deleteBeforePtr, deleteAfterPos, and deleteAfterPtr functions.

v1.6.4
- Updated sList, dList, csList, and cdList classes and demos.
	- Added findTailReturnPos and findTailReturnPtr functions.

v1.6.3
- Updated dList and demo.
	- Added movePtrToFront, movePtrToBack, movePtrUp, and movePtrDown functions.

v1.6.2
- Updated sList class and demo.
	- Added swap function.
- Fixed bug in populateCmd function preventing passing of second integer to updateDataByPos function in list classes, demos.

v1.6.1
- Added bubbleSort sorting function to sList class and demo.
- Updated commands header/cpp.
	- Added getBool function.
	- Added listFuncsBool string vector to hold sorting function names.
	- Renamed listFuncsNoInts to listFuncs, stackFuncsNoInts to stackFuncs, queueFuncsNoInts to queueFuncs, and fifoFuncsNoInts to fifoFuncs.

v1.6.0
- Added random class and addRandomNodes function to sList, dList, csList, and cdList demos.
	- Added input3 integer member to command struct. 
	- Updated README.

v1.5.18
- Updated cdList class and demo.
	- Added movePtrToFront, movePtrToBack, movePtrUp, and movePtrDown functions.

v1.5.17
- Updated error codes for slist, dList, csList, and cdList class functions and their respective demos.

v1.5.16
- Updated sList and demo.
	- Renamed moveToFrontByPos to movePosToFront and updated function.
	- Added movePosToBack, movePtrToFront, and movePtrToBack functions.

v1.5.15
- Updated populateCmd function so that only one demo can run at a time.

v1.5.14
- Updated startMenu and populateCmd functions.
	- Fixed bug causing crash on entering invalid command.
	- Fixed bug causing keyboard input lock out when "stop" command enterd with no thread running.
	- All integer fields checked for valid input before pushing commands to thread.
	- Command struct input fields now cleared after invalid commands.
	- Removed command struct funcsInts, funcsNoInts fields and consolidated all list function integer/no integer lists.

v1.5.13
- Updated csList and demo.
	- Added findMinReturnPos, findMaxReturnPos, findMaxReturnPos, and findMaxReturnPtr functions.
- Updated sList and demo with deleteNodeByPos function.
- Updated README.

v1.5.12
- Updated csList and demo.
	- Added addNodeByPos, returnDataByPtr, updateDataByPtr, and findDataReturnPos functions.

v1.5.11
- Updated cdList class and demo.
	- Added findMinReturnPos, findMinReturnPtr, findMaxReturnPos, and findMaxReturnPtr functions.

v1.5.10
- Updated cdList class and demo.
	- Added deleteNodeByPtr, updateDataByPos, findDataReturnPos, findDataReturnPtr, and reverse functions.

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