#include "blockchain.h"

Blockchain::Blockchain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficult = 3;
}

void Blockchain::AddBlock(Block bNew) {
	bNew.previousHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficult);
	_vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}
