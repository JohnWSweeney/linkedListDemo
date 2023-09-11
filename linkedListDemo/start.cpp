#include "start.h"
#include "commands.h"
#include "threads.h"
#include "atomicBool.h"

void getCommands(std::vector<std::string> &tokens)
{
	do {
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (std::getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

void startMenu(bool &running)
{
	std::mutex m;
	std::condition_variable cv;
	cmd cmd;

	std::unique_lock<std::mutex> lk(m);
	while (true)
	{
		std::vector<std::string> tokens;
		getCommands(tokens);

		int result = populateCmd(tokens, cmd);
		if (result != 0)
		{
			cmd = { };
		}

		if (cmd.function == "start")
		{
			status = true;
			startThread(std::ref(m), std::ref(cv), std::ref(cmd));
			cv.wait(lk);
		}
		else if (cmd.function == "stop")
		{
			status = false;
			cv.notify_one();
			cv.wait(lk);
		}
		else if (cmd.function == "exit")
		{
			if (status == true)
			{
				status = false;
				cv.notify_one();
				cv.wait(lk);
			}
			running = false;
			return;
		}
		else
		{
			cv.notify_one();
			cv.wait(lk);
		}
	}
}