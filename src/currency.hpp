#include <iostream>
#include <map>

#pragma once

class Currency {
	public:
		Currency(std::string name, std::uint32_t max);

		// the name of the currency
		std::string name;

		// the capacity of the currency;
		uint32_t capacity;

		// the ledger with account balances
		std::map<std::string, uint32_t> mLedger;

		// retrieve balance of `address`
		uint32_t Balance(std::string address);

		// transfer `amount` of currency from `sender` to `recipient`
		// and returns a transaction hash
		std::string Transfer(uint32_t amount, std::string sender, std::string recipient );

	private:
		std::string TransactionHash(std::string from, std::string to);
};
