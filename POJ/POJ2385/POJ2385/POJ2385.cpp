/*
 * http://poj.org/problem?id=2385
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int fall[1010];
int dp[1010][32][2];
int t, w;

int changePoint(int point)
{
	return point == 1 ? 2 : 1;
}

int dfs(int depth, int move, int point)
{
	int res;

	if (dp[depth][move][point - 1] >= 0) {
		return dp[depth][move][point - 1];
	}
	
	if (depth == t) {
		res = 0;
	}
	else if (move == w) {
		res = dfs(depth + 1, move, point) + (fall[depth] == point);
	}
	else {
		res = max(dfs(depth + 1, move, point) + (fall[depth] == point), dfs(depth + 1, move + 1, changePoint(point)) + (fall[depth] != point));
	}

	return dp[depth][move][point-1] = res;
}

int main()
{
	cin >> t >> w;

	// memset(dp, -1, sizeof(dp));

	for (int i = 0; i < t; i++){
		cin >> fall[i];
	}

	for (int i = t - 1; i >= 0; i--){
		for (int j = 0; j <= w; j++){
			for (int k = 0; k < 2; k++){
				if (j == w) {
					dp[i][j][k] = dp[i+1][j][k] + (fall[i] == k+1);
				}
				else {
					dp[i][j][k] = max(dp[i + 1][j][k] + (fall[i] == k + 1), dp[i + 1][j + 1][changePoint(k + 1) - 1] + (fall[i] != k + 1));
				}
			}
		}
	}

	cout << dp[0][0][0] << endl;
	// cout << dfs(0, 0, 1) << endl;

	return 0;
}