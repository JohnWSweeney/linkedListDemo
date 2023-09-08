#include "fifoDemo.h"

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