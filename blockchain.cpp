#include "blockchain.h"
#include <map>

Blockchain::Blockchain() {
	vBlocks.emplace_back(Block(0, "Genesis Block"));

	nDifficulty = 3;
}

void Blockchain::AddBlock(Block newBlock, string account) {
	int previousBalance = GetLastBlock().ledger[account];

	newBlock.previousHash = GetLastBlock().GetHash();
	newBlock.MineBlock(nDifficulty, account);
	newBlock.ledger[account] = previousBalance + 1;

	std::cout << "New balance: " << newBlock.ledger[account] << endl;

	vBlocks.push_back(newBlock);
}

Block Blockchain::GetLastBlock() const {
	return vBlocks.back();
}

