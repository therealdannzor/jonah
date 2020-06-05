#include <cstdint>
#include <vector>
#include "block.h"


class Blockchain {
	public:
		Blockchain();

		void AddBlock(Block bNew, string account);
		Block GetLastBlock() const;

		uint32_t nDifficulty;
		std::vector<Block> vBlocks;
};
