/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0033
 */

#include <iostream>
#include <cstdio>

using namespace std;

int line[10];
bool ans = false;

void dfs(int depth, int left, int right)
{
	if (depth == 10){
		ans = true;
	}

	if (left < line[depth]){
		dfs(depth + 1, line[depth], right);
	}
	else if (right < line[depth]){
		dfs(depth + 1, left, line[depth]);
	}
}

int main()
{
	int n;

	cin >> n;

	while (n--){
		for (int i = 0; i < 10; i++){
			cin >> line[i];
		}
		
		ans = false;

		dfs(0, 0, 0);

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}