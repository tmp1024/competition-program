/*
 * http://poj.org/problem?id=3616
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int>P;

int n, m, r;
vector<P> data[1000000];
int dp[1000000 + 1];
bool flag[1000000];

int main()
{
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		data[a].push_back(make_pair(min(b + r, n), c));
		flag[a] = true;
	}

	for (int i = 0; i < n; i++){
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (flag[i]){
			for (int j = 0; j < data[i].size(); j++){
				dp[data[i][j].first] = max(dp[data[i][j].first], dp[i] + data[i][j].second);
			}
		}
	}

	cout << dp[n] << endl;

	return 0;
}