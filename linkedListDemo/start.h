#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <mutex>
#include <condition_variable>

void getCommands(std::vector<std::string> &tokens);
void startMenu(bool &running);