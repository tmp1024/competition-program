/*
 * http://poj.org/problem?id=3040
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> P;

int main()
{
	int n, c;

	cin >> n >> c;

	vector<P> coin;

	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		coin.push_back(P(a, b));
	}

	sort(coin.begin(), coin.end(), greater<P>());

	int ans = 0;
	int size = coin.size();

	while (true){
		bool flag = false;
		int cost = 0;
		for (int i = 0; i < n; i++){
			int j;
			int mainas = 0;
			for (j = 1; j <= coin[i].second; j++){
				if (cost + (coin[i].first * j) >= c){
					flag = true;
					break;
				}
			}
			coin[i].second -= (j - 1);
			cost += coin[i].first * (j - 1);
		}

		if (cost < c){
			for (int i = n - 1; i >= 0; i--){
				if (coin[i].second){
					coin[i].second--;
					flag = true;
					break;
				}
			}
		}
		if (!flag) break;
		ans++;
	}

	cout << ans << endl;

	return 0;
}