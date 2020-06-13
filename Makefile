FILES = main.cpp blockchain.cpp block.cpp sha256.cpp account.cpp currency.cpp cli.cpp
TARGET_BINARY = TestChain

build: 
	@clang++ -Wall -std=c++11 $(FILES) -o $(TARGET_BINARY)

clean:
	@rm $(TARGET_BINARY)
