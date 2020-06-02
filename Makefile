build: main.cpp blockchain.cpp block.cpp sha256.cpp
	clang++ -Wall -std=c++11 main.cpp blockchain.cpp block.cpp sha256.cpp -o TestChain

