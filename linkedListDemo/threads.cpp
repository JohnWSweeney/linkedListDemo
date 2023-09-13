#include "threads.h"
#include "functions.h"

// define function pointer.
void (*ptr)(std::mutex &m, std::condition_variable &cv, cmd &cmd);

void startThread(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	// assign function pointer to chosen list type function.
	if (cmd.listType == "sList")
	{
		ptr = sFunc;
	}
	if (cmd.listType == "csList")
	{
		ptr = csFunc;
	}
	else if (cmd.listType == "fifo")
	{
		ptr = fifoFunc;
	}
	else if (cmd.listType == "stack")
	{
		ptr = stackFunc;
	}

	std::thread newThread(ptr, std::ref(m), std::ref(cv), std::ref(cmd));
	newThread.detach();
}