#include "blockchain.h"
#include "account.h"

int main() {
	Blockchain bChain = Blockchain();
	Account newAccount = Account("hello");

	std::string address = newAccount.Address();

	std::cout << "Mining block 1... " << endl;
	bChain.AddBlock(Block(1, "Block 1 Data"), address); 

	std::cout << "Mining block 2... " << endl;
	bChain.AddBlock(Block(2, "Block 2 Data"), address);

	std::cout << "Mining block 3.. " << endl;
	bChain.AddBlock(Block(3, "Block 3 Data"), address);

	return 0;
}
