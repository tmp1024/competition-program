#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

struct dice {
	int a[6];

	void move(char c) {
		int tmp;
		if (c == 'E') {
			tmp = a[0];
			a[0] = a[3];
			a[3] = a[5];
			a[5] = a[2];
			a[2] = tmp;
		}
		if (c == 'W') {
			tmp = a[0];
			a[0] = a[2];
			a[2] = a[5];
			a[5] = a[3];
			a[3] = tmp;
		}
		if (c == 'S') {
			tmp = a[0];
			a[0] = a[4];
			a[4] = a[5];
			a[5] = a[1];
			a[1] = tmp;
		}
		if (c == 'N') {
			tmp = a[0];
			a[0] = a[1];
			a[1] = a[5];
			a[5] = a[4];
			a[4] = tmp;
		}
	}
};

int main()
{
	struct dice d;
	for (int i = 0; i < 6; i++) {
		cin >> d.a[i];
	}
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		d.move(str[i]);
	}
	cout << d.a[0] << endl;

	return 0;
}