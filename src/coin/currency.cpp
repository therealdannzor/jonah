#include "currency.hpp"
#include "intrange.hpp"
#include <chrono>
#include <sstream>


Currency::Currency(std::string newName, uint32_t newCapacity)
: name(newName)
{
	IntRange ir(newCapacity);
	CustomInt ci; 
	ci.num = ir;

	std::map<std::string, struct CustomInt> m;
	
	mLedger = m;
}

int Currency::Balance(std::string account) {
	return mLedger[account].num.Value();
}

void Currency::Fund(std::string account, int amount) {
	mLedger[account].num.Add(amount);
}

std::string Currency::Transfer(uint32_t amount, std::string sender, std::string recipient) {
	if (mLedger[sender].num.Value() < amount)
		return "";

	mLedger[sender].num.Sub(amount);
	mLedger[recipient].num.Add(amount);

	return TransactionHash(sender, recipient);
}

std::string Currency::TransactionHash(std::string from, std::string to) {
	std::stringstream ss;
	auto now = std::chrono::system_clock::now();
	auto in_time = std::chrono::system_clock::to_time_t(now);

	ss << from << to << in_time;

	return ss.str();
}
