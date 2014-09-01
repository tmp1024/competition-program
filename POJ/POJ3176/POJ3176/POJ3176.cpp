/*
 * http://poj.org/problem?id=3176
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int pin[351][351];

	cin >> n;

	fill(pin[0], pin[0] + 351 * 351, 0);

	int k = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= k; j++){
			cin >> pin[i][j];
		}
		k++;
	}

	k = n - 1;
	for (int i = n-2; i >= 0; i--){
		for (int j = 0; j < k; j++){
			pin[i][j] += max(pin[i + 1][j], pin[i + 1][j + 1]);
		}
	}

	cout << pin[0][0] << endl;

	return 0;
}