#include "blockchain.hpp"
#include "account.hpp"


int main() {
	bool running = true;
	std::string command;
	std::string target;


	CLI cli = CLI("Jonahcoin", 490);

	// Create a chain and two accounts
	Blockchain bChain = Blockchain(cli);
	//Account alice_account = Account("a");
	//Account bob_account = Account("b");
	//std::string AliceAddr = alice_account.Address();
	//std::string BobAddr = bob_account.Address();
	
	cout << "JonahChain started, waiting for input..." << endl;

	while(running)
	{
		std::cout << "-> ";
		cin >> command >> target;
		bChain.cmd.Operation(command, target);
	}
	

	return 0;
}
