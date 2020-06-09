#include "blockchain.h"
#include <map>

Blockchain::Blockchain(std::string currencyName,  uint32_t capacity)
: coin(Currency(currencyName, capacity))
{
	vBlocks.emplace_back(Block(0, "Genesis Block"));

	nDifficulty = 3;
}


void Blockchain::AddBlock(Block newBlock, string account) {
	newBlock.previousHash = GetLastBlock().GetHash();
	newBlock.MineBlock(nDifficulty, account);
	coin.mLedger[account]++;
	vBlocks.push_back(newBlock);
}


Block Blockchain::GetLastBlock() const {
	return vBlocks.back();
}


