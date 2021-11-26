#include <vcl.h>
#include <windows.h>
#include <iostream>
#include <algorithm>
#include "md5.hpp"
#pragma hdrstop
#pragma argsused
#include <tchar.h>
#include <stdio.h>
using namespace std;

void vainfiga(string&);

void vainfiga(string& testo) {
	transform(begin(testo), end(testo), begin(testo), [](char c)->char {
		if (not isalpha(c))
			return c; char const pivot = isupper(c) ? 'A' : 'a';
		return (c - pivot + 13) % 26 + pivot;});
}

int _tmain(int argc, _TCHAR* argv[]) {

	string email;
	cout << "Keygen per Excel2MySQL" << endl;
	cout << "Email: ";
	cin >> email;

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
	replace(licenza.begin(), licenza.end(), '0', 'C');
	replace(licenza.begin(), licenza.end(), 'O', 'K');
	replace(licenza.begin(), licenza.end(), 'I', '3');
	replace(licenza.begin(), licenza.end(), '1', '7');
	replace(licenza.begin(), licenza.end(), 'L', 'T');
	replace(licenza.begin(), licenza.end(), 'S', 'W');
	replace(licenza.begin(), licenza.end(), 'B', 'V');
	replace(licenza.begin(), licenza.end(), '8', '4');
	replace(licenza.begin(), licenza.end(), 'Z', 'X');
	cout << "Licenza : " << licenza.substr(0, 15) << endl;
	system("pause");
	return 0;
}
