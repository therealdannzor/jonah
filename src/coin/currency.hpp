#include <iostream>
#include <map>
#include "intrange.hpp"

#pragma once

class Currency {
	public:
		Currency(std::string name, std::uint32_t max);

		// the name of the currency
		std::string name;

		// the ledger with account balances
		std::map<std::string, struct CustomInt> mLedger;

		// retrieve balance of `address`
		int Balance(std::string address);

		// add coins to an account `address`
		void Fund(std::string address, int amount);

		// transfer `amount` of currency from `sender` to `recipient`
		// and returns a transaction hash
		std::string Transfer(uint32_t amount, std::string sender, std::string recipient );

	private:
		std::string TransactionHash(std::string from, std::string to);
};
