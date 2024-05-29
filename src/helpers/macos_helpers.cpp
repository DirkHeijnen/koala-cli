#include "../../include/helpers/macos_helpers.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <unistd.h>
#include <sys/wait.h>
#include <stdexcept>
#include <cstring>
#include <vector>

std::string exec(const char* cmd, bool shouldPrint) {
    std::array<char, 128> buffer;
    std::string result;

    // Append " 2>&1" to the command to redirect stderr to stdout
    char *cmdStr = new char[strlen(cmd)+strlen(" 2>&1")+1];
    strcpy(cmdStr, cmd);
    strcat(cmdStr, " 2>&1");

    // Use popen with "r" mode to read the output
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmdStr, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Read the output into the result string
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        if (shouldPrint) {
           std::cout << buffer.data();
        }
        result += buffer.data();
    }

    return result;
}

std::string execInteractive(const std::string& cmd, const std::vector<std::string>& inputs) {
    int pipe_stdout[2];
    int pipe_stdin[2];
    pid_t pid;
    char buffer[128];
    std::string result;

    if (pipe(pipe_stdout) == -1 || pipe(pipe_stdin) == -1) {
        throw std::runtime_error("pipe() failed!");
    }

    if ((pid = fork()) == -1) {
        throw std::runtime_error("fork() failed!");
    }

    if (pid == 0) {
        // Child process
        close(pipe_stdout[0]); // Close read end of stdout pipe
        dup2(pipe_stdout[1], STDOUT_FILENO);
        dup2(pipe_stdout[1], STDERR_FILENO);
        close(pipe_stdout[1]);

        close(pipe_stdin[1]); // Close write end of stdin pipe
        dup2(pipe_stdin[0], STDIN_FILENO);
        close(pipe_stdin[0]);

        execl("/bin/sh", "sh", "-c", cmd.c_str(), (char*)NULL);
        _exit(127); // If execl fails
    } else {
        // Parent process
        close(pipe_stdout[1]); // Close write end of stdout pipe
        close(pipe_stdin[0]);  // Close read end of stdin pipe

        for (const auto& input : inputs) {
            write(pipe_stdin[1], input.c_str(), input.size());
            write(pipe_stdin[1], "\n", 1);
        }
        close(pipe_stdin[1]);

        ssize_t count;
        while ((count = read(pipe_stdout[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[count] = '\0';
            std::cout << buffer;
            result += buffer;
        }

        close(pipe_stdout[0]);
        waitpid(pid, NULL, 0);
    }

    return result;
}