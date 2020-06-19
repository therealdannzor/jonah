#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include "signer.hpp"
#include "sodium.h"


Signer::Signer() {
	std::vector<Keychain> keys;
	collection = keys;
}

void Signer::Create() {
	// generate a public-private keypair
	unsigned char publickey[crypto_sign_PUBLICKEYBYTES];
	unsigned char secretkey[crypto_sign_SECRETKEYBYTES];
	crypto_sign_keypair(publickey, secretkey);

	// add pair to a keychain
	Keychain kc;
	std::memcpy(kc.pk, publickey, crypto_sign_PUBLICKEYBYTES);
	std::memcpy(kc.sk, secretkey, crypto_sign_SECRETKEYBYTES);

	// add keychain to collection
	collection.push_back(kc);
}

std::vector<Keychain> Signer::GetKeys() {
	return collection;
}

bool Signer::Save() {
	std::ofstream file;
	file.open("key.txt");
	std::stringstream ss;

	for (const auto &e : this->collection) {
		ss.clear();

		for (int i=0; i < crypto_sign_PUBLICKEYBYTES; ++i) {
			ss << std::hex << e.pk[i];
		}

		std::string public_key = ss.str();
		if (public_key.length() != 32) {
			std::cout << "err length: " << public_key.length() << std::endl;
			return false;
		}

		std::cout << "Public key: " << public_key << std::endl;
		file << public_key << std::endl;

		ss.str("");
		ss.clear();
	}

	file.close();
	
	return true;
}
	
