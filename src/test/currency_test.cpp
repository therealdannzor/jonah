#include "catch.hpp"
#include "../currency.hpp"


TEST_CASE( "account balances can increase and drecrease within limits" , "[currency]" ) {
	std::string account = "0x1";
	Currency c = Currency("TestCoin", 5);

	SECTION( "adding 1 coin to account results in correct balance" ) {
		c.mLedger[account] = 1;
		int balance = c.Balance(account);
		REQUIRE(balance == 1);
	}
}
