#include <iostream>

class Account {
	public:
		// local node address
		std::string address;
		std::string Address();

		Account(std::string password);

	private:
		// password to unlock the account
		std::string passPhrase;
};
