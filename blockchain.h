#include <cstdint>
#include <vector>
#include "block.h"

using namespace std;


class Blockchain {
	public:
		Blockchain();
		void AddBlock(Block bNew);

	private:
		uint32_t _nDifficult;
		vector<Block> _vChain;
		Block _GetLastBlock() const;
};
