#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s, p;
	cin >> s;
	cin >> p;
	bool ans = false;
	for (int i = 0; i < s.size(); i++) {
		char tmp = s[0];
		for (int j = 0; j < s.size() - 1; j++) {
			s[j] = s[j + 1];
		}
		s[s.size() - 1] = tmp;
		if (s.find(p) != string::npos) {
			ans = true;
			break;
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}