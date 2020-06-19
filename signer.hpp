#include <iostream>
#include <vector>
#include "sodium.h"

#pragma once


// Public-private keypair
struct Keychain {
	// Public key
	unsigned char pk[crypto_sign_PUBLICKEYBYTES];
	
	// Secret key
	unsigned char sk[crypto_sign_SECRETKEYBYTES];
};

class Signer {
	public:
		Signer();

		// Create a keypair
		void Create();

		// Return the list of public keys
		std::vector<Keychain> GetKeys();

		// Save the current keychain to a local keyfile
		bool Save();

		// Read and load the local keyfile
		bool Read();

	private:
		std::vector<Keychain> collection;
};


