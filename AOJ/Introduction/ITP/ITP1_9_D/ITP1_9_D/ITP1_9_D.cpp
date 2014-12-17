#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		if (s == "replace") {
			int a, b;
			cin >> a >> b >> s;
			for (int i = 0; i < s.size(); i++) {
				str[i + a] = s[i];
			}
		}
		else if (s == "reverse") {
			int a, b;
			cin >> a >> b;
			reverse(str.begin() + a, str.begin() + b + 1);
		}
		else {
			int a, b;
			cin >> a >> b;
			for (int i = a; i <= b; i++) {
				printf("%c", str[i]);
			}
			putchar('\n');
		}
	}

	return 0;
}