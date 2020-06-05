#include "account.h"
#include "sha256.h"
#include <sstream>

Account::Account(std::string pass) {
	passPhrase = pass;

	std::stringstream ss; 
	time_t now = std::time(nullptr);
	ss << pass << now; 
	std::string hashed = sha256(ss.str());
	address = hashed;

}

std::string Account::Address() {
	return address;
}
