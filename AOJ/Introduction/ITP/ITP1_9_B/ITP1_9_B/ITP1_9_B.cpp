#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s;
	int m;
	while (cin >> s && s != "-") {
		cin >> m;
		for (int i = 0; i < m; i++) {
			int h;
			cin >> h;
			string right = s.substr(h);
			string left = s.substr(0, h);
			s = right + left;
		}
		cout << s << endl;
	}

	return 0;
}