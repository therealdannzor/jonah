#include <cstdint>
#include <vector>
#include "block.h"
#include "currency.h"


class Blockchain {
	public:
		Blockchain(std::string name, uint32_t capacity);

		// Block methods
		std::vector<Block> vBlocks; // chain the blocks together
		void AddBlock(Block bNew, string account); // append a block to the chain
		Block GetLastBlock() const; // retrieve the last appended block

		// Cryptocurrency
		Currency coin;

		
		// Config
		uint32_t nDifficulty; // mining difficulty


};
