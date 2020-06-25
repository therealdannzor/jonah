#include "blockchain.hpp"
#include "account.hpp"
#include "signer.hpp"


int main() {
	std::string command;
	std::string target;
	


	CLI cli = CLI("Jonahcoin", 490);

	// Create a chain and two accounts
	Blockchain bChain = Blockchain(cli);
	
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
