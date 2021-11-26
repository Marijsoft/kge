#include <vcl.h>
#include <windows.h>
#include <iostream>
#include <algorithm>
#include "md5.hpp"
#pragma hdrstop
#pragma argsused
#include <tchar.h>
#include <stdio.h>

void vainfiga(std::string&);

void vainfiga(std::string& text) {
	std::transform(begin(text), end(text), begin(text), [](char c)->char {
		if (not std::isalpha(c))
			return c;

		char const pivot = std::isupper(c) ? 'A' : 'a';
		return (c - pivot + 13) % 26 + pivot;});
}

int _tmain(int argc, _TCHAR* argv[]) {

	std::string email;
	std::cout << "Keygen per Excel2MySQL"<< std::endl;
	std::cout << "Email: ";
	std::cin >> email;

	int cnt = 0;
	for (auto i : email) {
		email[cnt++] = tolower(i);
	}
	auto licenza = md5::md5_hash_hex(email);
	cnt = 0;
	for (auto i : licenza) {
		licenza[cnt++] = toupper(i);
	}
	vainfiga(licenza);
	std::replace(licenza.begin(), licenza.end(), '0', 'C');
	std::replace(licenza.begin(), licenza.end(), 'O', 'K');
	std::replace(licenza.begin(), licenza.end(), 'I', '3');
	std::replace(licenza.begin(), licenza.end(), '1', '7');
	std::replace(licenza.begin(), licenza.end(), 'L', 'T');
	std::replace(licenza.begin(), licenza.end(), 'S', 'W');
	std::replace(licenza.begin(), licenza.end(), 'B', 'V');
	std::replace(licenza.begin(), licenza.end(), '8', '4');
	std::replace(licenza.begin(), licenza.end(), 'Z', 'X');
	std::cout << "Licenza : " << licenza.substr(0, 15) << std::endl;
	system("pause");
    	return 0;
}


