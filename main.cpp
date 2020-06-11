#include "blockchain.hpp"
#include "account.hpp"

int main() {
	bool running;


	// Create a chain and two accounts
	Blockchain bChain = Blockchain("Jonahcoin", 490);
	Account alice_account = Account("a");
	Account bob_account = Account("b");
	std::string AliceAddr = alice_account.Address();
	std::string BobAddr = bob_account.Address();

	// Build an identical chain of three blocks for both accounts
	std::cout << "Mining block 1... " << endl;
	bChain.AddBlock(Block(1, "Block 1 Data"), AliceAddr); 
	bChain.AddBlock(Block(1, "Block 1 Data"), BobAddr); 
	std::cout << "Mining block 2... " << endl;
	bChain.AddBlock(Block(2, "Block 2 Data"), AliceAddr);
	bChain.AddBlock(Block(2, "Block 2 Data"), BobAddr);
	std::cout << "Mining block 3.. " << endl;
	bChain.AddBlock(Block(3, "Block 3 Data"), AliceAddr);
	bChain.AddBlock(Block(3, "Block 3 Data"), BobAddr);

	// Check that both have 3 coins each
	uint32_t aliceBal = bChain.coin.Balance(AliceAddr);
	uint32_t bobBal = bChain.coin.Balance(BobAddr);
	cout << "Alice balance is: " << aliceBal << endl;
	cout << "Bob balance is: " << bobBal << endl;

	// Transfer two coins from Bob to Alice
	std::string txHash = bChain.coin.Transfer(2, BobAddr, AliceAddr);
	cout << "Transaction hash: " << txHash << endl;

   // Check successful transfer
	aliceBal = bChain.coin.Balance(AliceAddr);
	bobBal = bChain.coin.Balance(BobAddr);
	cout << "Alice new balance is: " << aliceBal << endl;
	cout << "Bob new balance is: " << bobBal << endl;
	

	return 0;
}
