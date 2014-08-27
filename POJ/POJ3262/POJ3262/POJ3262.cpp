/*
 * http://poj.org/problem?id=3262
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _cow{
	int t;
	int d;

	bool operator < (const _cow& c) const {
		return t * c.d < c.t * d;
	}
}cow;

int main()
{
	int n;

	cin >> n;

	cow cows[100010];
	long long int sum = 0;

	for (int i = 0; i < n; i++){
		cin >> cows[i].t >> cows[i].d;
	}

	sort(cows, cows + n);

	long long int ans = 0;

	for (int i = 0; i < n; i++){
		ans += sum * cows[i].d;
		sum += 2 * cows[i].t;
	}

	cout << ans << endl;

	return 0;
}