#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int sum = 0;
	int minans = 1 << 24, maxans = -(1 << 24);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		minans = min(minans, tmp);
		maxans = max(maxans, tmp);
		sum += tmp;
	}
	cout << minans << " " << maxans << " " << sum << endl;

	return 0;
}