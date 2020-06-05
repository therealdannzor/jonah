#include <iostream>

typedef std::string txHash;
typedef std::string account;

class Account {
	public:
		// local node address
		account address;
		account Address();

		Account(std::string password);

};
