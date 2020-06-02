#include "block.h"
#include "sha256.h"
#include <sstream>
#include <chrono>

Block::Block(uint32_t nIndexIn, const string &sDataIn) {
	_nonce = -1;
	_time = time(nullptr);
}

string Block::GetHash() {
	return previousHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
	char cstr[nDifficulty+1];
	for (uint32_t i = 0; i < nDifficulty; ++i) {
		cstr[i] = '0';
	}

	cstr[nDifficulty] = '\0';
	string res = string(cstr);

	auto start = std::chrono::steady_clock::now();

	do {
		_nonce++;
		_hash = _CalculateHash();
	} while (_hash.substr(0, nDifficulty) != res);

	auto end = std::chrono::steady_clock::now();
	
	std::chrono::duration<double> elapsed_time = end-start;

	cout << "Block mined: " << _hash << " (elapsed time: " << elapsed_time.count() << "s)" << endl;
}

inline string Block::_CalculateHash() const {
	std::stringstream ss;
	ss << _index << _time << _data << _nonce << previousHash;

	return sha256(ss.str());
}
