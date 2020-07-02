#include "catch.hpp"
#include "../blockchain.hpp"
#include "../coin/currency.hpp"
#include "../cli.hpp"


TEST_CASE( "blockchain can add blocks and correctly return the amount of blocks" ) {
	Currency c = Currency("TestCoin");
	CLI cli = CLI();
	Blockchain bc = Blockchain(c, cli);
	std::string account = "0x1"; 

	SECTION( "the chain starts with the correct (default) difficulty and contains the genesis block" ) {
		int expected = 3;
		int actual = bc.Difficulty();
		REQUIRE(actual == expected);

		Block genesisBlock = Block(0, "Genesis Block");
		Block retrievedBlock = bc.GetLastBlock();
		REQUIRE(retrievedBlock == genesisBlock);
	}

	SECTION( "the chain contains one block when initialised (genesis block) and increases when expanded" ) {
		// check that size is 1 from the beginning
		int actual = bc.Size();
		int expected = 1;
		REQUIRE(actual == expected);

		// check that the size has grown by 1 
		Block block = Block(1, "Test Data");
		bc.AddBlock(block, account);
		expected = 2;
		actual = bc.Size();
		REQUIRE(actual == expected);

		// check that the user has received the mining reward
		expected = 1;
		actual = c.Balance(account);
		REQUIRE(actual == expected);
	}

}
