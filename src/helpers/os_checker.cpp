#include "helpers/os_checker.hpp"

bool isWindows() {
    #ifdef _WIN32
        return true;
    #else
        return false;
    #endif
}

bool isMacOS() {
    #ifdef __APPLE__
        return true;
    #else
        return false;
    #endif
}

bool isLinux() {
    #ifdef __linux__
        return true;
    #else
        return false;
    #endif
}