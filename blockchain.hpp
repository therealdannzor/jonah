#include <cstdint>
#include <vector>
#include "block.hpp"
#include "cli.hpp"


class Blockchain {
	public:

		// Iinitialisation and config 
		Blockchain(CLI cli);
		std::string coinID; // coin name identifier
		uint32_t nCapacity; // maximum coin supply
		uint32_t nDifficulty; // mining difficulty
		CLI cmd; // user access to coin commands

		// Block methods
		std::vector<Block> vBlocks; // chain the blocks together
		void AddBlock(Block bNew, string account); // append a block to the chain
		Block GetLastBlock() const; // retrieve the last appended block


		


};
