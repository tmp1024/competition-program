/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1 << 12;

int W, H, N;
char field[1000][1000];
int d[1000][1000];
int Nx[10], Ny[10];
int sx, sy;
int gx, gy;
typedef pair<int, int> P;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs()
{
	queue<P> que;

	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 1000; j++){
			d[i][j] = INF;
		}
	}

	que.push(P(sx, sy));
	d[sx][sy] = 0;

	while (que.size()){
		P p = que.front(); que.pop();
		
		if (p.first == gx && p.second == gy){
			break;
		}

		for (int i = 0; i < 4; i++){
			int nx = p.first + dx[i], ny = p.second + dy[i];

			if (0 <= nx && nx < H && 0 <= ny && ny < W && field[nx][ny] != 'X' && d[nx][ny] == INF){
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}

void solve()
{
	int ans = 0;

	cin >> H >> W >> N;

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> field[i][j];
			
			if (field[i][j] == 'S'){
				Nx[0] = i;
				Ny[0] = j;
			}
			else if ('1' <= field[i][j] && field[i][j] <= '9'){
				Nx[field[i][j] - '0'] = i;
				Ny[field[i][j] - '0'] = j;
			}
		}
	}

	for (int i = 0; i < N; i++){
		sx = Nx[i];
		sy = Ny[i];
		gx = Nx[i+1];
		gy = Ny[i+1];
		ans += bfs();
	}

	cout << ans << endl;
}

int main()
{
	solve();

	return 0;
}