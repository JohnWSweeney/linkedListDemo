#pragma once
#include <string>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "commands.h"

void sFunc(std::mutex &m, std::condition_variable &cv, cmd &cmd);
void csFunc(std::mutex &m, std::condition_variable &cv, cmd &cmd);
void fifoFunc(std::mutex &m, std::condition_variable &cv, cmd &cmd);