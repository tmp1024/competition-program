/*
 * http://poj.org/problem?id=1979
*/

#include <iostream>
#include <cstdio>

using namespace std;

int W, H;
char map[20][21];
int counter;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

void bfs(int x, int y)
{
	counter++;

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < W && 0 <= ny && ny < H && map[ny][nx] == '.'){
			map[ny][nx] = '#';
			bfs(nx, ny);
		}
	}
}

int main()
{
	int start_x, start_y;
	char c;

	while (cin >> W >> H && W && H){
		counter = 0;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				cin >> c;
				map[i][j] = c;
				if (c == '@'){
					start_x = j;
					start_y = i;
				}
			}
		}

		bfs(start_x, start_y);

		cout << counter << endl;
	}

	return 0;
}