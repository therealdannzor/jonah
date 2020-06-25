#include <cstdint>
#include <iostream>

#pragma once

class Block {
	public:
		std::string previousHash;
		std::string GetHash();
		void MineBlock(uint32_t nDifficulty, std::string account);
		Block(uint32_t nIndexIn, const std::string &sDataIn);

	
	private:
		uint32_t _index;
		int64_t _nonce;
		std::string _data;
		std::string _hash;
		time_t _time;

		std::string CalculateHash() const;
};
