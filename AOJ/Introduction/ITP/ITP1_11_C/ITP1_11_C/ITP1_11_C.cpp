#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>

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
	struct dice d1;
	for (int i = 0; i < 6; i++) {
		cin >> d1.a[i];
	}
	struct dice d2;
	for (int i = 0; i < 6; i++) {
		cin >> d2.a[i];
	}
	char c[] = "EEENWWWS";
	int i, j;
	for (i = 0; i < 24; i++) {
		d1.move(c[i % 8]);
		for (j = 0; j < 6; j++) {
			if (d1.a[j] != d2.a[j]) break;
		}
		if (j == 6) break;
	}
	if (i == 24) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}