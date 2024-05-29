#include "../helpers/os_checker.cpp";
#include "../helpers/macos_helpers.cpp";
#include "../helpers/string_utils.cpp";


void update() {

    const std::string green("\033[1;32m");
    const std::string cyan("\033[0;36m");
    const std::string reset("\033[0m");

    if (isWindows()) {
        std::cout << green << "Koala sees your are using windows, which is not supported yet." << reset << std::endl;
        return;
    }

    if (isMacOS()) {
        std::cout << green << "Koala sees your are using MacOS, it will now update your brew installation to the latest available version." << reset << std::endl;
        std::cout << cyan << "Do you want to continue? (Y)es/(N)o: " << reset;
        std::string answer;
        std::cin >> answer;

        if (answer == "Y" || answer == "y" || answer == "yes" || answer == "Yes") {
            std::vector<std::string> inputs;
            inputs.push_back("Yes");
            std::cout << execInteractive("brew update", inputs) << std::endl;
            std::cout << green << "Koala has updated brew to the latest version for you." << reset << std::endl;

            std::string brew_version = exec("brew --version", false);
            std::string brew_version_number = brew_version.substr(std::string("Homebrew ").length());
            std::cout << green << "You are now running brew on version: " << brew_version_number << reset << std::endl;
        } else {
            std::cout << green << "You chose not to upgrade brew, koala will not help you." << reset << std::endl;
        }

        return;
    }

    if (isLinux()) {
        std::cout << "Koala sees your are using Linux, it will now update your apt installation to the latest available version." << std::endl;
        std::cout << cyan << "Do you want to continue? (Y)es/(N)o: " << reset;
        std::string answer;
        std::cin >> answer;

        if (answer == "Y" || answer == "y" || answer == "yes" || answer == "Yes") {
            std::vector<std::string> inputs;
            execInteractive("apt update", inputs);
            std::cout << green << "Koala has updated apt to the latest version for you." << reset << std::endl;

            std::string apt_version = exec("apt --version", false);
            replace(apt_version, "apt ", "");
            replace(apt_version, " (amd64)", "");

            std::cout << green << "You are now running apt on version: " << apt_version << reset << std::endl;
        } else {
            std::cout << green << "You chose not to upgrade apt, koala will not help you." << reset << std::endl;
        }

        return;
    }

}