#pragma once

#include <vector>
#include <string>

std::string exec(const char* cmd, bool shouldPrint = true);
std::string execInteractive(const std::string& cmd, const std::vector<std::string>& inputs);