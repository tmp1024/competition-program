#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			cout << " " << i;
			continue;
		}
		int x = i;
		do {
			if (x % 10 == 3) {
				cout << " " << i;
				break;
			}
		} while ((x /= 10) != 0);
	}

	putchar('\n');

	return 0;
}