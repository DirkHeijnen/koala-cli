#include <string>
#include <iostream>

#include "../helpers/os_checker.hpp"
#include "../helpers/macos_helpers.hpp"


void upgrade() {

    const std::string green("\033[1;32m");
    const std::string cyan("\033[0;36m");
    const std::string reset("\033[0m");

    if (isWindows()) {
        std::cout << green << "Koala sees your are using windows, which is not supported yet." << reset << std::endl;
        return;
    }

    if (isMacOS()) {
        std::cout << green << "Koala sees your are using MacOS, it will now upgrade your brew packages to the latest available version." << reset << std::endl;
        std::cout << exec("brew upgrade --dry-run") << std::endl;
        std::cout << cyan << "Do you want to continue? (Y)es/(N)o: " << reset;
        std::string answer;
        std::cin >> answer;

        if (answer == "Y" || answer == "y" || answer == "yes" || answer == "Yes") {
            std::vector<std::string> inputs;
            inputs.push_back("Yes");
            std::cout << execInteractive("brew upgrade", inputs) << std::endl;
            std::cout << green << "Koala has upgraded your brew pacakges to their latest versions for you." << reset << std::endl;
        } else {
            std::cout << green << "You chose not to upgrade, koala will not help you." << reset << std::endl;
        }

        return;
    }
    
    if (isLinux()) {
        std::cout << "Koala sees your are using Linux, it will now upgrade your apt packages to the latest available version." << std::endl;
        std::cout << cyan << "Do you want to continue? (Y)es/(N)o: " << reset;
        std::string answer;
        std::cin >> answer;

        if (answer == "Y" || answer == "y" || answer == "yes" || answer == "Yes") {
            std::vector<std::string> inputs;
            execInteractive("apt upgrade -y", inputs);
            std::cout << green << "Koala has upgraded your apt packages to the latest version for you." << reset << std::endl;
        } else {
            std::cout << green << "You chose not to upgrade apt, koala will not help you." << reset << std::endl;
        }

        return;
    }
}