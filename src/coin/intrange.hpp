#include <iostream>
#include <limits>
#include <map>

#pragma once


class IntRange {
	public:
		IntRange();

		// max value
		int capacity;

		// getters
		int Capacity() const;
		int Value();

		friend class Currency;
	
	private:
		// stored value
		int value;

		// subtract a value
		void Sub(int val);

		// add a value
		void Add(int val);
};
