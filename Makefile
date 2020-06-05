FILES = main.cpp blockchain.cpp block.cpp account.cpp sha256.cpp
TARGET_BINARY = TestChain

build: 
	@clang++ -Wall -std=c++11 $(FILES) -o $(TARGET_BINARY)

clean:
	@rm $(TARGET_BINARY)
