#include <iostream>
#include <cstdio>

using namespace std;

int getsum(int y, int m, int d) {
	int res = 0;
	
	for (int i = 1; i < y; i++) {
		res += 365;
		if ((i % 4) == 0 && (i % 100) != 0 || (i % 400) == 0) {
			res += 1;
		}
	}

	for (int i = 1; i < m; i++) {
		res += 31;
		if (i == 4 || i == 6 || i == 9 || i == 11) {
			res -= 1;
		}
		if (i == 2) {
			res -= 3;
			if ((y % 4) == 0 && (y % 100) != 0 || (y % 400) == 0) {
				res += 1;
			}
		}
	}

	for (int i = 1; i < d; i++) {
		res += 1;
	}

	return res;
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	int uruuyear[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int usuayear[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
		if (y1 < 0 || m1 < 0 || d1 < 0 || y2 < 0 || m2 < 0 || d2 < 0) {
			break;
		}

		long long int ans = 0;

		cout << getsum(y2, m2, d2) - getsum(y1, m1, d1) << endl;
	}

	return 0;
}