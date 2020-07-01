#include <iostream>
#include <limits>

#pragma once


class IntRange {
	private:
		// max value
		int capacity;

		// stored value
		int current;

		// set a value
		void Set(int val);

		// allow access to private methods
		friend class Currency;
		friend class Blockchain;
	
	public:
		IntRange();
		IntRange(int val);

		// subtract a value
		void Sub(int val);

		// add a value
		void Add(int val);

		// getters
		int Capacity();
		int Value();
};


struct CustomInt {
	IntRange num;
};
