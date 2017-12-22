#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <openssl/des.h>

#include "StringUtils.h"
#include "StringUtils.cpp"

#include "Encryption.h"
#include "Encryption.cpp"

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	char * result;
	bool encryption = true;

	if ( argc != 3 ) {
    cout<<"usage: "<< argv[0] <<" [--e|--d] [string]\n";
	}
  else {
		if (strcmp(argv[1],"--e") == 0) encryption = true;
		if (strcmp(argv[1],"--d") == 0) encryption = false;

		string the_data = argv[2];
	 	const char * p_the_data = the_data.c_str();

	 	if (encryption == true) {
	 		result = Encryption::Encrypt("NppFTP00", Encryption::KeySize, p_the_data, the_data.length());
	 	} else {
	 		result = Encryption::Decrypt("NppFTP00", Encryption::KeySize, p_the_data, false);
	 	}

		std::cout << result;

	  //std::cout << result;
  }

	return 0;
}
