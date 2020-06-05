#include "blockchain.h"
#include <map>

Blockchain::Blockchain() {
	vBlocks.emplace_back(Block(0, "Genesis Block"));

	nDifficulty = 3;
}


void Blockchain::AddBlock(Block newBlock, string account) {
	int previousBalance = mLedger[account];

	newBlock.previousHash = GetLastBlock().GetHash();
	newBlock.MineBlock(nDifficulty, account);

	mLedger[account] = previousBalance + 1;

	std::cout << "New balance: " << mLedger[account] << endl;

	vBlocks.push_back(newBlock);
}


Block Blockchain::GetLastBlock() const {
	return vBlocks.back();
}


uint32_t Blockchain::Balance(std::string account) {
	return mLedger[account];
}


std::string Blockchain::Send(std::string from, std::string to, uint32_t amount) {
	return "0x";
}
