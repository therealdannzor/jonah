#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include "signer.hpp"
#include "sodium.h"


Signer::Signer()
{
	std::vector<Keychain> k;
	keys = k;
}

Keychain Signer::operator[](int i) {
	return keys[i];
}

void Signer::Create() {
	// generate a public-private keypair
	unsigned char publickey[crypto_box_PUBLICKEYBYTES];
	unsigned char secretkey[crypto_box_SECRETKEYBYTES];
	crypto_box_keypair(publickey, secretkey);

	// extract keypair as hexadecimal string
	const size_t pub_bin_len = crypto_box_PUBLICKEYBYTES;
	const size_t sec_bin_len = crypto_box_SECRETKEYBYTES;
	const size_t pub_hex_maxlen = pub_bin_len*2 + 1;
	const size_t sec_hex_maxlen = sec_bin_len*2 + 1;
	char* const pub_hex = new char[pub_hex_maxlen];
	char* const sec_hex = new char[sec_hex_maxlen];
	const unsigned char* const pub_bin = publickey;
	const unsigned char* const sec_bin = secretkey;
	sodium_bin2hex(pub_hex, pub_hex_maxlen, pub_bin, pub_bin_len);
	sodium_bin2hex(sec_hex, sec_hex_maxlen, sec_bin, sec_bin_len);

	// sanity checks
	int HEX_KEY_LENGTH = 64; // our keys are 32 bytes -> 64 hexadecimal characters
	size_t pub_result_length = strlen(pub_hex);
	if (pub_result_length != HEX_KEY_LENGTH) {
		std::cout << "Incorrect public key length; want 64, got: " << pub_result_length << std::endl;
		return;
	}
	size_t sec_result_length = strlen(sec_hex);
	if (sec_result_length != 64) {
		std::cout << "Incorrect secret key length; want 64, got: " << sec_result_length << std::endl;
	}

	// add pair to a keychain
	std::string pubkey = pub_hex;
	std::string seckey = sec_hex;
	Keychain kc{.pk = pubkey, .sk = seckey};

	// add keychain to collection
	keys.push_back(kc);
}

std::vector<Keychain> Signer::GetKeys() {
	return keys;
}

bool Signer::Save() {
	std::ofstream file;
	file.open("key.txt");

	for (auto it : keys) {
		if (it.pk.length() == 0) {
			std::cout << "Error: missing public key" << std::endl;
		} else {
			// hacky JSON format
			file << "{\"account\":\"" << it.pk << "\"," << "\"secret\":\"" << it.sk << "\"}" << std::endl;
		}
	}

	file.close();
	return true;
}
	
