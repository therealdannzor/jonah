#include "currency.hpp"
#include <chrono>
#include <sstream>

Currency::Currency(std::string newName, uint32_t newCapacity)
: name(newName), capacity(newCapacity)
{
}

uint32_t Currency::Balance(std::string account) {
	return mLedger[account];
}

std::string Currency::Transfer(uint32_t amount, std::string sender, std::string recipient) {
	if (mLedger[sender] < amount)
		return "";

	mLedger[sender] -= amount;
	mLedger[recipient] += amount;

	return TransactionHash(sender, recipient);
}

std::string Currency::TransactionHash(std::string from, std::string to) {
	std::stringstream ss;
	auto now = std::chrono::system_clock::now();
	auto in_time = std::chrono::system_clock::to_time_t(now);

	ss << from << to << in_time;

	return ss.str();
}
