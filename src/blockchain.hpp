#include <cstdint>
#include <vector>
#include "block.hpp"
#include "cli.hpp"

#pragma once

class Blockchain {
	public:

		// Iinitialisation and config 
		Blockchain(Currency currency, CLI cli);

		// coin name identifier
		std::string coinID; 

		// mining difficulty
		uint32_t nDifficulty; 

		 // cryptocurrency, as a storage of value
		Currency coin;

		// terminal interface access to chain commands
		CLI cmd; 

		// Block methods
		std::vector<Block> vBlocks; // chain the blocks together
		void AddBlock(Block bNew, std::string account); // append a block to the chain
		Block GetLastBlock() const; // retrieve the last appended block


		


};
