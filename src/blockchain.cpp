#include "blockchain.hpp"
#include "coin/intrange.hpp"
#include "coin/currency.hpp"

Blockchain::Blockchain(Currency c, CLI cli)
: coin(c), cmd(cli)
{
	vBlocks.emplace_back(Block(0, "Genesis Block"));

	nDifficulty = 3;
}


void Blockchain::AddBlock(Block newBlock, std::string account) {
	newBlock.previousHash = GetLastBlock().GetHash();
	newBlock.MineBlock(nDifficulty, account);
	coin.mLedger[account].num.Add(1);
	vBlocks.push_back(newBlock);
}


Block Blockchain::GetLastBlock() const {
	return vBlocks.back();
}


