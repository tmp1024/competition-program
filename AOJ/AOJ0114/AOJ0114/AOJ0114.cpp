#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

template<typename T>
T gcd(T a, T b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

template<typename T>
T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	long long int a1, m1, a2, m2, a3, m3;

	while (cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3) {
		if (a1 == 0 && m1 == 0 && a2 == 0 && m2 == 0 && a3 == 0 && m3 == 0) break;
		long long int ans = 0;
		long long int x = 1, y = 1, z = 1;
		long long int a = 1, b = 1, c = 1;

		x = a1 * x % m1;
		y = a2 * y % m2;
		z = a3 * z % m3;

		for (; x != 1; a++) {
			x = a1 * x % m1;
		}
		for (; y != 1; b++) {
			y = a2 * y % m2;
		}
		for (; z != 1; c++) {
			z = a3 * z % m3;
		}

		ans = lcm(lcm(a, b), c);

		cout << ans << endl;
	}

	return 0;
}