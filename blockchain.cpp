#include "blockchain.hpp"
#include <map>

Blockchain::Blockchain(CLI cli)
: cmd(cli)
{
	vBlocks.emplace_back(Block(0, "Genesis Block"));

	nDifficulty = 3;
}


void Blockchain::AddBlock(Block newBlock, string account) {
	newBlock.previousHash = GetLastBlock().GetHash();
	newBlock.MineBlock(nDifficulty, account);
	cmd.coin.mLedger[account]++;
	vBlocks.push_back(newBlock);
}


Block Blockchain::GetLastBlock() const {
	return vBlocks.back();
}


