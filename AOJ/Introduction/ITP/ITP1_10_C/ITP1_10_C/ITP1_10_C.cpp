#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n && n) {
		vector<int> s(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			sum += s[i];
		}
		double ave = (double)sum / n;
		double a = 0;

		for (int i = 0; i < n; i++) {
			a += (s[i] - ave) * (s[i] - ave);
		}
		a /= n;
		printf("%f\n", sqrt(a));
	}
	return 0;
}