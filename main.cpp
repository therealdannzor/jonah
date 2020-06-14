#include "blockchain.hpp"
#include "account.hpp"


int main() {
	bool running = true;
	std::string command;
	std::string target;


	CLI cli = CLI("Jonahcoin", 490);

	// Create a chain and two accounts
	Blockchain bChain = Blockchain(cli);
	
	std::cout << "JonahChain started, waiting for input..." << std::endl;

	while(running)
	{
		std::cout << "-> ";
		std::cin >> command >> target;
		bChain.cmd.Operation(command, target);
	}
	

	return 0;
}
