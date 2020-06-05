#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

class Block {
	public:
		map<std::string, int> ledger;
		string previousHash;
		string GetHash();
		void MineBlock(uint32_t nDifficulty, string account);

		Block(uint32_t nIndexIn, const string &sDataIn);
		int Balance(string address);
	
	private:
		uint32_t _index;
		int64_t _nonce;
		string _data;
		string _hash;
		time_t _time;

		string CalculateHash() const;
};
