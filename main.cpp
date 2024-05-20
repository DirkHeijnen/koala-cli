#include <iostream>
#include <string>
#include <vector>
#include "./src/commands/help.command.cpp"
#include "./src/commands/update.command.cpp"
#include "./src/commands/upgrade.command.cpp"


int main(int argc, char *argv[]) {
	int exitCode = -1;

    if (argc == 1 || argc >= 1 && std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        help();
        return 0;
    }

    if (argc >= 1 && std::string(argv[1]) == "-u" || std::string(argv[1]) == "--update") {
        update();
        return 0;
    }

    if (argc >= 1 && std::string(argv[1]) == "-g" || std::string(argv[1]) == "--upgrade") {
        upgrade();
        return 0;
    }

    return exitCode;
}
