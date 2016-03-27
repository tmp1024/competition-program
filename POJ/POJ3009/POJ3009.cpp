/*
 * http://poj.org/problem?id=3009
 */

#include <iostream>
#include <cstdio>

using namespace std;

int H, W;
int counter;
int start_x, start_y;
char mp[20][21];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int depth)
{
	if (depth >= counter){
		return;
	}

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];

		if (0 <= nx && nx < W && 0 <= ny && ny < H && mp[ny][nx] != '1'){
			while (true){
				if (mp[ny][nx] == '3'){
					counter = depth;
					return;
				}

				nx += dx[i], ny += dy[i];

				if (!(0 <= nx && nx < W && 0 <= ny && ny < H)) break;
				if (0 <= nx && nx < W && 0 <= ny && ny < H && mp[ny][nx] == '1'){
					mp[ny][nx] = '0';
					dfs(nx - dx[i], ny - dy[i], depth + 1);
					mp[ny][nx] = '1';
					break;
				}
			}
		}
	}
}

int main()
{
	while (cin >> W >> H && W && H){
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				cin >> mp[i][j];
				if (mp[i][j] == '2'){
					start_x = j;
					start_y = i;
				}
			}
		}

		counter = 11;
		dfs(start_x, start_y, 1);

		cout << (counter == 11 ? -1 : counter) << endl;
	}

	return 0;
}