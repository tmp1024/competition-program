#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string t;
	string w;
	cin >> w;
	int ans = 0;
	while (true) {
		cin >> t;
		if (t == "END_OF_TEXT") break;
		for (int i = 0; i < t.size(); i++) {
			if (isalpha(t[i])) t[i] = ::tolower(t[i]);
		}
		if (t == w) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}