# linkedListDemo

A console app exploring linked lists and their applications. Currently, only the circular singly linked list and FIFO class functions can be controlled with console commands. The others will be added in a future release. The Windows executable is compiled with C++17.

## Functions
The app opens a console window on startup. Enter the *command* keywords separated by a space. Commands are case-sensitive. 

### Circular Singly (CS) Linked List
To start or stop a circular singly linked thread, enter:
> *start cs*

> *stop*

CS functions "init", "addNodeFront", "addNodeBack", "deleteNodeFront", "deleteNodeBack", "isEmpty", "size", and "print" are currently supported. Once the CS thread is running enter:
> *init integer*

to initialize the list with *integer*. 

Nodes can be added to the beginning or end of the list with the "addNodeFront" and "addNodeBack" functions, respectively:
> *addNodeFront integer*

> *addNodeBack integer*

Similarly, the first and last nodes can be removed by:
> *deleteNodeFront*

> *deleteNodeBack*

To check if the list is empty, enter:
> *isEmpty*

To find the list's node count, enter:
> *size*

To view the list's current contents, enter:
> *print*

### FIFO (First-In-First-Out)
The FIFO is implemented as a singly linked list. The FIFO function names are based on the Xilinx FIFO conventions. To start or stop a FIFO thread, enter:
> *start fifo*

> *stop*

FIFO functions "init", "write", "read", "size", and "print" are currently supported. Once the FIFO thread is running enter:
> *init integer*

to initialize the FIFO's linked list with *integer*. This is the first FIFO entry. To make another entry at the end of the list, enter: 
> *write integer*

To read out the entry at the beginning of the list, enter:
> *read*

To find the FIFO's total entry count, enter:
> *size*

To view the FIFO's current contents, enter:
> *print*

## Future Updates
- ?

## Download
[linkedListDemo v1.5.6](https://github.com/JohnWSweeney/linkedListDemo/releases/download/v1.5.6/linkedListDemo_v1_5_6.exe) [79 kB]

## ChangeLog
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