#include "account.hpp"
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

void Account::Append(Transaction tx) {
	nonce++;
	tx.UpdateNonce(nonce);
	vTransactionPool.push_back(tx);
}

std::string Account::Send(std::string recipient, uint32_t amount) {
	// TODO: pop first element in vector, send to verify func,
	// and dispatch tx
	
	return "dummy transaction hash";
}
