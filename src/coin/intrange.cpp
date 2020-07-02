#include "intrange.hpp"

// no negative account balances allowed
const int MIN_BALANCE = 0;

// there is a limit on being rich too
const int MAX_BALANCE = std::numeric_limits<int>::max();



IntRange::IntRange()
: capacity(MAX_BALANCE)
{
	// note to self: if we forget to initialise this we will have a bad time in crypto world
	value = 0;
}

void IntRange::Sub(int toSubtract) {
	if (toSubtract <= value && toSubtract > 0 && value - toSubtract >= 0)
		value -= toSubtract;
}


void IntRange::Add(int toAdd) {
	if (toAdd > MAX_BALANCE || toAdd > capacity) {
		return;
	}

	else if (toAdd <= MIN_BALANCE) {
		return;
	}
	
	else if (toAdd + value < MIN_BALANCE) {
		return;
	}

	value += toAdd;
}


int IntRange::Capacity() const { return capacity; }
int IntRange::Value() { return value; }
