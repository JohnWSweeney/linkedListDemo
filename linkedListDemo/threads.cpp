#include "threads.h"
#include "functions.h"

// define function pointer.
void (*ptr)(std::mutex &m, std::condition_variable &cv, cmd &cmd);

void startThread(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	// assign function pointer to chosen list type function.
	if (cmd.listType == "sList")
	{
		ptr = sDemo;
	}
	else if (cmd.listType == "dList")
	{
		ptr = dDemo;
	}
	else if (cmd.listType == "csList")
	{
		ptr = csDemo;
	}
	else if (cmd.listType == "cdList")
	{
		ptr = cdDemo;
	}
	else if (cmd.listType == "fifo")
	{
		ptr = fifoDemo;
	}
	else if (cmd.listType == "stack")
	{
		ptr = stackDemo;
	}

	std::thread newThread(ptr, std::ref(m), std::ref(cv), std::ref(cmd));
	newThread.detach();
}