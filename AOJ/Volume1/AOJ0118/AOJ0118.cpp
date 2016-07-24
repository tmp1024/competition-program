/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0118
 *
 * 1‰ñ–Ú
 *  Å‰‚Éö‚éêŠ‚ª'.'‚É‚È‚Á‚Ä‚¢‚È‚©‚Á‚½
 *
 * 2‰ñ–Ú
 *  “ü—Í‚ª‹t‚¾‚Á‚½
 */

#include <iostream>
#include <cstdio>

using namespace std;

int W, H;
char mp[110][110];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, char mark)
{
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];

		if (0 <= nx && nx < W && 0 <= ny && ny < H && mp[ny][nx] == mark){
			mp[ny][nx] = '.';
			dfs(nx, ny, mark);
		}
	}
}

int main()
{
	while (cin >> H >> W && W && H){
		int counter = 0;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				cin >> mp[i][j];
			}
		}

		char mark;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if (mp[i][j] != '.'){
					counter++;
					mark = mp[i][j];
					mp[i][j] = '.';
					dfs(j, i, mark);
				}
			}
		}
		
		cout << counter << endl;
	}

	return 0;
}