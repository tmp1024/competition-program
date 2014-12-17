#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>

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
	int q;
	cin >> q;
	srand((unsigned int)time(NULL));
	char c[] = "ESWN";
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		while (true) {
			d.move(c[rand() % 4]);
			if (d.a[0] == a) {
				if (b == d.a[1]) {
					cout << d.a[2] << endl;
					break;
				}
				if (b == d.a[2]) {
					cout << d.a[4] << endl;
					break;
				}
				if (b == d.a[3]) {
					cout << d.a[1] << endl;
					break;
				}
				if (b == d.a[4]) {
					cout << d.a[3] << endl;
					break;
				}
			}
		}
	}

	return 0;
}