## binary output
NAME := JonahChain

## source files
SRC := main.cpp blockchain.cpp block.cpp sha256.cpp account.cpp currency.cpp cli.cpp transaction.cpp signer.cpp

## compiler and flags
CC := clang++
FLAGS := -Wall -std=c++11

## dependencies
FLAGS += -I.static/libsodium-stable/src/libsodium/include
FLAGS += -L.static/libsodium-stable/src/libsodium/.libs


dep:

build: 
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) -lsodium

clean:
	@rm $(NAME)
