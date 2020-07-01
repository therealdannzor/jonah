#include "transaction.hpp"
#include <sstream>

Transaction::Transaction(std::string from, std::string to, uint32_t amount, std::string sig)
: sender(from), recipient(to), value(amount)
{

}

// without a digital signature mechanism of the sender,
// we are currently open to transaction spoof exploits
std::string Transaction::Hash() {
	std::stringstream ss;
	ss << sender << recipient << value;

	return ss.str();
}

bool Transaction::VerifyTransaction() {
	// SHA256 output is 32 bytes (ascii characters)
	if (sender.length() != 32 || recipient.length() != 32)
		return false;
	if (sender == recipient)
		return false;
	if (value < 1)
		return false;
	return true;
}

void Transaction::UpdateNonce(std::uint16_t val) {
	nonce = val;
}
