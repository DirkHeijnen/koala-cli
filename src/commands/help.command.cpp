#include <iostream>

void help(){

    const std::string red("\033[0;31m");
    const std::string green("\033[1;32m");
    const std::string yellow("\033[1;33m");
    const std::string cyan("\033[0;36m");
    const std::string magenta("\033[0;35m");
    const std::string reset("\033[0m");

    std::cout << green;
    std::cout << R"(     __                      __         )" << std::endl;
    std::cout << R"(  .-'  `'.._...-----..._..-'`  '-.      )" << std::endl;
    std::cout << R"( /                                \     )" << cyan << "Koala CLI v0.0" << green << std::endl;
    std::cout << R"( |  ,   ,'                '.   ,  |     )" << std::endl;
    std::cout << R"(  \  '-/                    \-'  /      )" << cyan << "Developed by:" << green << std::endl;
    std::cout << R"(   '._|          _           |_.'       )" << cyan << "Dirk Heijnen" << green << std::endl;
    std::cout << R"(      |    /\   / \    /\    |          )" << std::endl;
    std::cout << R"(      |    \/   | |    \/    |          )" << cyan << "Art by:" << green << std::endl;
    std::cout << R"(       \        \"/         /           )" << cyan << "Joan G. Stark" << green << std::endl;
    std::cout << R"(        '.    =='^'==     .'            )" << std::endl;
    std::cout << R"( jgs      `'------------'`              )" << std::endl;
 
    std::cout << reset
    << "\n\n"
    << "Koala Usage: \n\n"
    << "Command        Arguments                Description\n"
    << "------         ---------                -----------\n"
    << "-h, --help     [none]                   Shows this help display\n"
    << "-g, --upgrade  [none]                   Upgrades your package manger (chocolatey / brew / apt) \n"
    << std::endl;
}
