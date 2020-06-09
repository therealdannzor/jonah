#include <iostream>
#include "transaction.h"

class Account {
	public:
		// local node address
		std::string address;
		std::string Address();

		Account(std::string password);

	private:
		// signs a transaction object and returns a receipt
		std::string SignTransaction(std::string key, Transaction tx);

		// sends a transaction to `recipient` with value `amount`
		std::string Send(std::string recipient, uint32_t amount);

};
