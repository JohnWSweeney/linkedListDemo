#pragma once
#include <vector>
#include <mutex>
#include <condition_variable>
#include "commands.h"

void startDemoThread(std::mutex &m, std::condition_variable &cv, cmd &cmd);