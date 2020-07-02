#include "catch.hpp"
#include "../coin/currency.hpp"


TEST_CASE( "account balances can increase within limits when being funded" , "[currency]" ) {
	std::string account = "0x1";
	Currency c = Currency("TestCoin");

	SECTION( "fund account with 1 coin results in correct balance" ) {
		c.Fund(account, 1);
		int actual = c.Balance(account);
		int expected = 1;
		REQUIRE(actual == expected);
	}

	SECTION( "fund account with a lot of coins results in correct balance" ) {
		int amount = std::numeric_limits<int>::max()-1;
		c.Fund(account, amount);
		int actual = c.Balance(account);
		int expected = amount;
		REQUIRE(actual == expected);
	}

	SECTION( "fund account with a negative amount of coins results in correct balance" ) {
		c.Fund(account, -2147448);
		int actual = c.Balance(account);
		REQUIRE(actual == 0);
	}

	SECTION( "fund account such that its balance overflows will have no additional effect" ) {
		c.Fund(account, 10);
		int expected = c.Balance(account);
		CHECK(expected == 10); 
		int max_balance = std::numeric_limits<int>::max();
		c.Fund(account, max_balance); 
		int actual = c.Balance(account);
		REQUIRE(actual == expected);
	}
}

TEST_CASE( "account balances can decrease within limits when being ", "[currency]" ) {
	std::string account = "0x2";
	Currency c = Currency("TestCoin");

	SECTION( "fund account with 3 coins and defund 2 coins results in correct balance (1)" ) {
		c.Fund(account, 3);
		c.Defund(account, 2);
		int expected = 1;
		int actual = c.Balance(account);
		REQUIRE(actual == expected); 
	}

	SECTION( "fund account with 1 coin and defund 2 coins results in no change" ) {
		c.Fund(account, 2);
		c.Defund(account, 3);
		int expected = 2; 
		int actual = c.Balance(account);
		REQUIRE(actual == expected);
	}

	SECTION( "fund and defund account with same amount results in initial state" ) {
		c.Fund(account, 5);
		c.Defund(account, 5); 
		int actual = c.Balance(account);
		REQUIRE(actual == 0);
	}

	SECTION( "defund account when it is already empty results in no change" ) {
		c.Defund(account, 1);
		int actual = c.Balance(account);
		REQUIRE(actual == 0);
	}

	SECTION( "defund account with a negative amount results in no change" ) {
		c.Fund(account, 1);
		c.Defund(account, -1); 
		int actual = c.Balance(account);
		int expected = 1;
		REQUIRE(actual == expected);
	}
}

TEST_CASE( "account balances are correctly changed when making transfers", "[currency]" ) {
	std::string alice = "0xa";
	std::string bob = "0xb";
	Currency c = Currency("TestCoin");

	SECTION( "a coin transfer from alice to bob results in correct balances" ) {
		c.Fund(alice, 1);
		c.Transfer(1, alice, bob);
		int aliceBalance = c.Balance(alice);
		int bobBalance = c.Balance(bob); 
		REQUIRE(aliceBalance == 0);
		REQUIRE(bobBalance == 1);
	}

	SECTION( "a coin transfer from alice with more than which exists results in no change" ) {
		c.Fund(alice, 1);
		c.Transfer(2, alice, bob);
		int aliceBalance = c.Balance(alice);
		int bobBalance = c.Balance(bob);
		REQUIRE(aliceBalance == 1);
		REQUIRE(bobBalance == 0); 
	}

	SECTION( "a coin transfer from alice with an negative amount results in no change" ) {
		c.Fund(alice, 1);
		c.Transfer(-1, alice, bob);
		int aliceBalance = c.Balance(alice);
		int bobBalance = c.Balance(bob);
		REQUIRE(aliceBalance == 1);
		REQUIRE(bobBalance == 0); 
	}



}
