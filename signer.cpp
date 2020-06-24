#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include "json.h"
#include "reader.h"
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


const std::string FILENAME = "key.json";

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
		return;
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


bool Signer::Read() {
	// check if there is a keyfile to read
	std::ifstream file(FILENAME, std::ifstream::binary);
	bool open = file.is_open();
	if (!open) {
		std::cout << "Error: file "<< FILENAME << " not found" << std::endl; 
		return false;
	}

	// read keyfile
	Json::Value root;
	Json::CharReaderBuilder builder;
	std::string errs;
	bool parsedSuccessful = Json::parseFromStream(builder, file, &root, &errs);
	if (!parsedSuccessful) {
		std::cout << "Error: failed to parse configuration: " << errs << std::endl;
		return false;
	}

	// check if key pair already exists (to avoid duplication)
	std::string pubkey = root["account"].asString();
	for (auto it : keys) {
		if (it.pk == pubkey) {
			std::cout << "Public key " << pubkey << "already loaded, aborting" << std::endl;
			return false;
		}
	}
	

	// add keyfile content to keychain
	std::string seckey = root["secret"].asString();
	Keychain kc{.pk = pubkey, .sk = seckey};
	keys.push_back(kc);

	file.close();

	return true;
}


bool Signer::Save() {
	std::ofstream file;
	file.open(FILENAME);

	for (auto it : keys) {
		if (it.pk.length() == 0 || it.sk.length() == 0) {
			std::cout << "Error: missing one or several keys" << std::endl;
		} else {
			Json::Value json;
			json["account"] = it.pk;
			json["secret"] = it.sk;
			file << json << std::endl;
		}
	}

	file.close();
	return true;
}
	
