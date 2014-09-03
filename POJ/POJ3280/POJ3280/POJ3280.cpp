/*
 * http://poj.org/problem?id=3280
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1 << 24;

int n, m;
int cost[26];
int dp[2010][2010];

int main()
{
	cin >> n >> m;

	string s;
	cin >> s;

	for (int i = 0; i < n; i++){
		char c;
		int add, era;

		cin >> c >> add >> era;

		cost[c - 'a'] = min(add, era);
	}

	for (int i = 0; i < m; i++){
		fill_n(dp[i], m + 1, INF);
		dp[i][i] = dp[i][i + 1] = 0;
	}

	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			int k = i + j;
			if (j > 0){
				dp[j - 1][k] = min(dp[j - 1][k], dp[j][k] + cost[s[j - 1] - 'a']);
			}
			if (k < m){
				dp[j][k + 1] = min(dp[j][k + 1], dp[j][k] + cost[s[k] - 'a']);
			}
			if (j > 0 && k < m && s[j - 1] == s[k]){
				dp[j - 1][k + 1] = min(dp[j - 1][k + 1], dp[j][k]);
			}
		}
	}

	cout << dp[0][m] << endl;

	return 0;
}