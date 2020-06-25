#include <iostream>
#include <vector>
#include "transaction.hpp"

#pragma once

class Account {
	public:
		Account(std::string password);

		// local node address
		std::string address;
		std::string Address();

	private:
		// stores all the local transactions in an account
		std::vector<Transaction> vTransactionPool;

		// appends a pending transaction to local tx pool
		void Append(Transaction tx);

		// amount of local transactions submitted
		std::uint16_t nonce;

		// sends a transaction to `recipient` with value `amount`
		std::string Send(std::string recipient, uint32_t amount);
};
