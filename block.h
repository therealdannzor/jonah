#include <cstdint>
#include <iostream>

using namespace std;


class Block {
	public:
		string previousHash;
		string GetHash();
		void MineBlock(uint32_t nDifficulty);

		Block(uint32_t nIndexIn, const string &sDataIn);
	
	private:
		uint32_t _index;
		int64_t _nonce;
		string _data;
		string _hash;
		time_t _time;

		string _CalculateHash() const;
};
