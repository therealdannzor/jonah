#include <iostream>
#include <vector>
#include "sodium.h"

#pragma once

// Public-private keypair
struct Keychain {
	// Public key
	std::string pk;
	
	// Secret key
	std::string sk;
};

class Signer {
	public:
		Signer();

		Keychain operator[](int i);

		// Create a keypair
		void Create();

		// Return the list of public keys
		std::vector<Keychain> GetKeys();

		// Save the current keychain to a local keyfile
		bool Save();

		// Read and load the local keyfile
		bool Read();

		std::vector<Keychain> keys;
};

