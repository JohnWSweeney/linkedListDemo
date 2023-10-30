#include "threads.h"
#include "demos.h"

// define function pointer.
void (*ptr)(std::mutex &m, std::condition_variable &cv, cmd &cmd);

void startDemoThread(std::mutex &m, std::condition_variable &cv, cmd &cmd)
{
	// assign function pointer to chosen list type function.
	if (cmd.demoType == "sList")
	{
		ptr = sDemo;
	}
	else if (cmd.demoType == "dList")
	{
		ptr = dDemo;
	}
	else if (cmd.demoType == "csList")
	{
		ptr = csDemo;
	}
	else if (cmd.demoType == "cdList")
	{
		ptr = cdDemo;
	}
	else if (cmd.demoType == "stack")
	{
		ptr = stackDemo;
	}
	else if (cmd.demoType == "queue")
	{
		ptr = queueDemo;
	}
	else if (cmd.demoType == "deque")
	{
		ptr = dequeDemo;
	}
	else if (cmd.demoType == "priorityQueue")
	{
		ptr = priorityQueueDemo;
	}
	else if (cmd.demoType == "fifo")
	{
		ptr = fifoDemo;
	}

	std::thread newThread(ptr, std::ref(m), std::ref(cv), std::ref(cmd));
	newThread.detach();
}