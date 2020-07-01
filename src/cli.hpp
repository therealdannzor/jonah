#include <iostream>
#include "coin/currency.hpp"

#pragma once

class CLI {
	public:
		CLI();
		
		std::string Operation(std::string cmd, std::string target);

	private:
		std::string balance(std::string account);
};
