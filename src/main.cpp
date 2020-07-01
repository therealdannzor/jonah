#include "blockchain.hpp"
#include "account.hpp"
#include "signer.hpp"
#include "coin/currency.hpp"


int main() {
	std::string command;
	std::string target;
	
	// initialise command line interface
	CLI cli = CLI();

	// initialise cryptocurrency
	Currency crypto = Currency("Jonahcoin", 490);

	// create chain
	Blockchain bChain = Blockchain(crypto, cli);
	
	std::cout << "JonahChain started, waiting for input..." << std::endl;

	Signer s;
	s.Create();
	//bool saved = s.Save();
	//std::cout << "Keys saved? " << saved << std::endl;
	bool read = s.Read();
	std::cout << "Keys read? " << read << std::endl;

	//bool running = true;
	//while(running)
	//{
		//std::cout << "-> ";
		//std::cin >> command >> target;
		//bChain.cmd.Operation(command, target);
	//}
	

	return 0;
}
