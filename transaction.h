#include <iostream>

class Transaction {
	private:
		// create new Transaction
		Transaction(std::string recipient, std::uint32_t amount, std::string key);

		std::string from;
		std::string to;
		std::uint32_t value;

		bool validTx;

};


