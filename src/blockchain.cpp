#include "blockchain.hpp"
#include "coin/intrange.hpp"
#include "coin/currency.hpp"

Blockchain::Blockchain(Currency c, CLI cli)
: coin(c), cmd(cli)
{
	blocks.emplace_back(Block(0, "Genesis Block"));

	difficulty = 3;
}


void Blockchain::AddBlock(Block newBlock, std::string account) {
	newBlock.previousHash = GetLastBlock().GetHash();
	newBlock.MineBlock(difficulty, account);
	coin.Fund(account, 1);
	blocks.push_back(newBlock);
}


Block Blockchain::GetLastBlock() const { return blocks.back(); }
int Blockchain::Size() { return blocks.size(); }
uint32_t Blockchain::Difficulty() { return difficulty; }
