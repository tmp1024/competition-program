/*
* http://poj.org/problem?id=2229
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

long long int ans[10000000];

int main()
{
	int n;

	cin >> n;

	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= 1000000; i++){
		if (i % 2 == 0) {
			ans[i] += ans[i / 2];
		}

		ans[i] += ans[i - 1];
		ans[i] %= 1000000000;
	}

	cout << ans[n] << endl;

	return 0;
}