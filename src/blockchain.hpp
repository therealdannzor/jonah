#include <cstdint>
#include <vector>
#include "block.hpp"
#include "cli.hpp"

#pragma once

class Blockchain {
	public:

		// Iinitialisation and config 
		Blockchain(Currency currency, CLI cli);

		// the chain of blocks
		std::vector<Block> blocks; 

		// mining difficulty
		uint32_t difficulty; 

		 // cryptocurrency, as a storage of value
		Currency coin;

		// terminal interface access to chain commands
		CLI cmd; 

		// append a block to the chain
		void AddBlock(Block bNew, std::string account); 

		// retrieve the last appended block
		Block GetLastBlock() const; 

		// retrieve the size of the chain (amount of blocks)
		int Size();

		// retrieve the current mining difficulty
		uint32_t Difficulty();


};
