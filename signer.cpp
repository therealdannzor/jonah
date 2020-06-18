#include <vector>
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

	printf("Key pair generated! Public key: %s", kc.pk);
}

std::vector<Keychain> Signer::GetKeys() {
	return collection;
}
