#pragma once
#include <vector>
#include <mutex>
#include <condition_variable>
#include "commands.h"

void startThread(std::mutex &m, std::condition_variable &cv, cmd &cmd);