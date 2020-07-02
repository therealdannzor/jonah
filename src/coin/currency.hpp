#include <iostream>
#include <map>
#include "intrange.hpp"

#pragma once

class Currency {
	public:
		Currency(std::string name);

		// the name of the currency
		std::string name;

		// the ledger with account balances
		std::map<std::string, IntRange> mLedger;

		// retrieve balance of `address`
		int Balance(std::string address);

		// add coins to an account `address`
		void Fund(std::string address, int amount);

		// remove coins of an account `address`
		void Defund(std::string address, int amount);

		// transfer `amount` of currency from `sender` to `recipient`
		// and returns a transaction hash
		std::string Transfer(uint32_t amount, std::string sender, std::string recipient );

	private:
		std::string TransactionHash(std::string from, std::string to);
};
