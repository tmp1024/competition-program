/*
 * http://poj.org/problem?id=3669
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1 << 12;

int M, X, Y;
int field[310][310];
int d[310][310];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

typedef pair<int, int> P;

int bfs()
{
	queue<P> que;

	if (field[1][1] == 0) return -1;

	for (int i = 0; i < 310; i++){
		for (int j = 0; j < 310; j++){
			d[i][j] = INF;
		}
	}

	que.push(P(1, 1));
	d[1][1] = 0;

	while (!que.empty()){
		P p = que.front(); que.pop();

		if (field[p.first][p.second] == INF) return d[p.first][p.second];

		for (int i = 0; i < 4; i++){
			int nx = p.first + dx[i], ny = p.second + dy[i];

			if (0 < nx && nx < 310 && 0 < ny && ny < 310 && field[nx][ny] - 1 > d[p.first][p.second] && d[nx][ny] == INF){
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}

	return -1;
}

int main()
{
	int dx[] = { 0, 1, 0, -1, 0 };
	int dy[] = { 0, 0, 1, 0, -1 };

	for (int i = 0; i < 310; i++){
		for (int j = 0; j < 310; j++){
			field[i][j] = INF;
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++){
		int X, Y, T;

		cin >> X >> Y >> T;

		X++, Y++;

		for (int j = 0; j < 5; j++){
			int nx = X + dx[j], ny = Y + dy[j];

			field[nx][ny] = min(field[nx][ny], T);
		}
	}

	cout << bfs() << endl;

	return 0;
}