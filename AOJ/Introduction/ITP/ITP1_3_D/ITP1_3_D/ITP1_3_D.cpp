#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, c;
	int ans = 0;

	cin >> a >> b >> c;

	for (int i = a; i <= b; i++) {
		if (c % i == 0) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}