#include "account.h"
#include "sha256.h"
#include <sstream>

Account::Account(std::string pass) {
	std::stringstream ss; 
	time_t now = std::time(nullptr);
	ss << pass << now; 
	address = sha256(ss.str());
}

std::string Account::Address() {
	return address;
}
