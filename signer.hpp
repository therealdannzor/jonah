#include <iostream>
#include <vector>
#include "sodium.h"

#pragma once

#define PUBLIC_KEY_LEN 40
#define SECRET_KEY_LEN 64

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

		// Read and load the local keyfile
		bool Read();

	private:
		std::vector<Keychain> collection;
};


