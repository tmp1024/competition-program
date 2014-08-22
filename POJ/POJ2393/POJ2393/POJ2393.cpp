/*
 * http://poj.org/problem?id=2393
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long long int n, s;
	long long int ans = 0;
	long long int shipment = 1 << 24;
	long long int c, y;

	cin >> n >> s;

	while (n--){
		cin >> c >> y;

		shipment = min(shipment+s, c);

		ans += y * shipment;
	}

	cout << ans << endl;

	return 0;
}