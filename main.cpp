#include <iostream>
#include "helpers.cpp"
#include "display.cpp"

int main(int argc, char *argv[]) {
	int exitCode = -1;

	
	if (argc == 1) {	
		showHelp();
		exitCode = 0;
	}

	for (int i = 0; i < argc; ++i){
		std::cout << "Arg " << i << ": " << argv[i] << std::endl;
		exitCode = 0;
	}

	return exitCode;
}
