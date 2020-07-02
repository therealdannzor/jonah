.PHONY = build test clean

## binary output
NAME := JonahChain

## source files
SRC =  sha256.cpp \
	   ./src/main.cpp \
	   ./src/blockchain.cpp \
	   ./src/block.cpp \
	   ./src/account.cpp \
	   ./src/coin/currency.cpp \
	   ./src/coin/transaction.cpp \
	   ./src/coin/intrange.cpp \
	   ./src/signer.cpp \
	   ./src/cli.cpp

## compiler and flags
CC := clang++
FLAGS := -Wall -std=c++11

## dependencies
FLAGS += -I.static/libsodium-stable/src/libsodium/include
FLAGS += -L.static/libsodium-stable/src/libsodium/.libs
FLAGS += -I.static/json/include
FLAGS += -L.static/json/lib

DEP_FLAGS := -lsodium -ljsoncpp

CATCH_SINGLE_INCLUDE := ./src/test/catch.hpp

TEST_FILES := ./sha256.cpp ./src/test/main_test.cpp ./src/test/currency_test.cpp ./src/coin/currency.cpp ./src/coin/intrange.cpp

build: 
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) $(DEP_FLAGS)

test:
	@$(CC) $(FLAGS) -I$(CATCH_SINGLE_INCLUDE) -o test_run $(TEST_FILES) && ./test_run
	@rm test_run

clean:
	@rm $(NAME)
