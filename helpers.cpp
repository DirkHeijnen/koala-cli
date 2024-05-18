#include <iostream>

int waitForUserInput() {
	int inputValue;

	std::cout << "Enter a number: " << std::endl;
	std::cin >> inputValue;

	return inputValue;
}

void printMessage(int number) {
	std::cout << "Your number was: " << number << "." << std::endl;
}
