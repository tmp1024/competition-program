#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int countarray[26];

int main()
{
	string in;
	while (getline(cin, in)) {
		if (cin.eof()) break;
		for (int i = 0; i < in.size(); i++) {
			if (isalpha(in[i])) {
				countarray[::tolower(in[i]) - 'a']++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%c : %d\n", i + 'a', countarray[i]);
	}

	return 0;
}