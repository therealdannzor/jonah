#include "../../sha256.h"
#include "currency.hpp"
#include "intrange.hpp"
#include <chrono>
#include <sstream>


Currency::Currency(std::string newName)
: name(newName)
{
	std::map<std::string, IntRange> m;
	mLedger = m;
}

int Currency::Balance(std::string account) {
	return mLedger[account].Value();
}

void Currency::Fund(std::string account, int amount) {
	mLedger[account].Add(amount);
}

void Currency::Defund(std::string account, int amount) {
	mLedger[account].Sub(amount);
}

std::string Currency::Transfer(uint32_t amount, std::string sender, std::string recipient) {
	if (mLedger[sender].Value() < amount)
		return "";

	mLedger[sender].Sub(amount);
	mLedger[recipient].Add(amount);

	return TransactionHash(sender, recipient);
}

std::string Currency::TransactionHash(std::string from, std::string to) {
	std::stringstream ss;
	auto now = std::chrono::system_clock::now();
	auto in_time = std::chrono::system_clock::to_time_t(now);

	ss << from << to << in_time;

	return "0x" + sha256(ss.str());
}
