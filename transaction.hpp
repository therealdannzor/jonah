#include <iostream>

class Transaction {
	public:
		std::string Hash();
		void UpdateNonce(std::uint16_t val);

	private:
		// create new Transaction
		Transaction(std::string from, std::string to, uint32_t amount, std::string sig);

		bool VerifyTransaction();

		std::string sender;
		std::string recipient;
		std::uint32_t value;
		std::string signature;
		std::uint16_t nonce;
};


