#include "intrange.hpp"


// no negative account balances allowed
const int MIN_BALANCE = 0;

// there is a limit on being rich too
constexpr int MAX_BALANCE = std::numeric_limits<int>::max();

// if there is no defined limit, we will make one
const int ARBITRARY_CAP = 100000;



IntRange::IntRange()
: capacity(ARBITRARY_CAP)
{
}

IntRange::IntRange(int cap) {
	if (cap > MAX_BALANCE)
		cap = MAX_BALANCE;
	if (cap < MIN_BALANCE)
		cap = ARBITRARY_CAP;

	capacity = cap;
}

// never have a balance that is below the minimum (0) or the maximum (given in the constructor)
void IntRange::Set(int val) {
	if (val > capacity)
		val = capacity;
	else if (val <= MIN_BALANCE)
		val = MIN_BALANCE;
	current = val;
}


void IntRange::Sub(int toSubtract) {
	if (toSubtract <= current)
		current -= toSubtract;
}


void IntRange::Add(int toAdd) {
	if (toAdd > MAX_BALANCE)
		return;
	
	else if (toAdd + current > MAX_BALANCE)
		return;

	current += toAdd;
}


int IntRange::Capacity() { return capacity; }
int IntRange::Value() { return current; }
