#include <iostream>
#include "currency.hpp"

#pragma once

class CLI {
	public:
		CLI(std::string name, uint32_t capacity);
		
		Currency coin;

		std::string Operation(std::string cmd, std::string target);

	private:
		std::string balance(std::string account);
};
