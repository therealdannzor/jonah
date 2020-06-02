#include <iostream>

using namespace std;

class Account {
	public:
		// local node balance
		uint32_t balance;
		uint32_t Balance();
		// external node balance
		uint32_t GetBalance(string address);

		// local node address
		string address;
		string Address();

	private:
		// password to unlock the account
		string passPhrase;
		void UnlockAccount(string passPhrase);

		bool unlocked;
		bool Unlocked();
}
