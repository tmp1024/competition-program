/*
 * http://poj.org/problem?id=3050
 */

#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

string field[5];
set<string> s;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int depth, string str)
{
	if (depth == 5){
		s.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];

		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5){
			//cout << nx << " " << ny << endl;
			dfs(nx, ny, depth + 1, str + field[nx][ny]);
		}
	}
}

int main()
{
	string str;

	for (int i = 0; i < 5; i++){
		getline(cin, str);

		string::iterator remove_it = remove(str.begin(), str.end(), ' ');
		str.erase(remove_it, str.end());

		field[i] = str;
	}

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			string st;
			st += field[i][j];
			dfs(i, j, 0, st);
		}
	}

	cout << s.size() << endl;

	return 0;
}