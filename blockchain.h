#include <cstdint>
#include <vector>
#include "block.h"


class Blockchain {
	public:
		// create a new blockchain
		Blockchain();

		// chain the blocks together
		std::vector<Block> vBlocks;

		// track of account balances
		map<std::string, int> mLedger;

		// append a block to the chain
		void AddBlock(Block bNew, string account);

		// retrieve the last appended block
		Block GetLastBlock() const;

		// mining difficulty
		uint32_t nDifficulty;

		// retrieve balance of `address`
		uint32_t Balance(string address);

		// send `amount` coins from `sender` to `recipient`
		std::string Send(std::string sender, std::string recipient, uint32_t amount);
};
