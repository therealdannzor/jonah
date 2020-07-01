#include <cstdint>
#include <vector>
#include "block.hpp"
#include "cli.hpp"

#pragma once

class Blockchain {
	public:

		// Iinitialisation and config 
		Blockchain(Currency currency, CLI cli);
		std::string coinID; // coin name identifier
		uint32_t nDifficulty; // mining difficulty
		Currency coin; // cryptocurrency, as a storage of value
		CLI cmd; // user access to coin commands

		// Block methods
		std::vector<Block> vBlocks; // chain the blocks together
		void AddBlock(Block bNew, std::string account); // append a block to the chain
		Block GetLastBlock() const; // retrieve the last appended block


		


};
