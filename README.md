# linkedListDemo

A console app exploring linked lists amd their applications.

## ChangeLog
v0.14.0
- Added circular singly linked list class csList.h/cpp.
	- Added init, addNodeFront, addNodeBack, accessNode, updateNode, size, isEmpty, and print functions.
- Added circularSinglyLinkedListDemo to demos.h/cpp.
- Changed circular singly linked list class name to cdList.h/cpp.

v0.13.0
- Added circular doubly linked list class dsList.h/cpp.
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