#include "cli.hpp"
#include <map>


CLI::CLI()
{
}

std::string CLI::Operation(std::string cmd, std::string target) {
	if (cmd == "getBalance") {
		if (target == "me")
			std::cout << "Your balance is: X" << std::endl;
		else std::cout << "Error: account missing" << std::endl;
	}

	return "try again";
}
