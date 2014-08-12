/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0525
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int grid[10][10001];
int ans;
int H, W;
bool flag[10];

void solve(){
	int res = 0;
	for (int i = 0; i < W; i++){
		int tmp = 0;
		for (int j = 0; j < H; j++){
			if (flag[j] && !grid[j][i] || !flag[j] && grid[j][i]){
				tmp++;
			}
		}

		if (tmp < H - tmp){
			res += H - tmp;
		}
		else {
			res += tmp;
		}
	}

	ans = max(ans, res);
}

void dfs(int depth){
	if (depth == H){
		solve();
		return;
	}

	flag[depth] = true;
	dfs(depth + 1);

	flag[depth] = false;
	dfs(depth + 1);
}

int main()
{
	
	while (cin >> H >> W && H && W){

		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				cin >> grid[i][j];
			}
		}

		ans = 0;
		dfs(0);
		cout << ans << endl;
	}

	return 0;
}