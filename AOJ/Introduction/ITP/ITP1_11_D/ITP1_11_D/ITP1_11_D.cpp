#include <iostream>
#include <cstdio>
#include <algorithm>

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

	bool equals(struct dice d) {
		char c[] = "EEENWWWS";
		bool flag;
		for (int i = 0; i < 24; i++) {
			flag = true;
			for (int j = 0; j < 6; j++) {
				if (a[j] != d.a[j]) {
					flag = false;
					break;
				}
			}
			if (flag) break;
			d.move(c[i % 8]);
		}
		return flag;
	}
};

int main()
{
	struct dice d[100];
	bool flag = false;
	int n;
	cin >> n;
	char c[] = "EEENWWWS";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> d[i].a[j];
		}
		for (int j = 0; j < i; j++) {
			if (d[i].equals(d[j])) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (flag) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}