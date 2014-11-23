#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool flag = false;
	while (n--) {
		if (flag) {
			putchar('\n');
		}
		flag = true;

		int puzzle[9][9];

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> puzzle[i][j];
			}
		}

		bool used[9][9] = { false };

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 9; k++) {
					if (j == k) continue;
					if (puzzle[i][j] == puzzle[i][k]) {
						used[i][j] = true;
					}
					if (puzzle[j][i] == puzzle[k][i]) {
						used[j][i] = true;
					}
				}
			}
		}

		int dx[] = { 0, 3, 6 };
		int dy[] = { 0, 3, 6 };
		for (int i = 0; i < 9; i++) {
			int nx, ny;
			nx = dx[i % 3];
			ny = dy[i / 3];
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 9; k++) {
					for (int l = 0; l < 9; l++) {
						if (k == l) continue;
						if (puzzle[ny + (k / 3)][nx + (k % 3)] == puzzle[ny + (l / 3)][nx + (l % 3)]) {
							used[ny + (k / 3)][nx + (k % 3)] = true;
						}
					}
				}
			}
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (used[i][j]){
					cout << "*" << puzzle[i][j];
				}
				else {
					cout << " " << puzzle[i][j];
				}
			}
			putchar('\n');
		}
	}

	return 0;
}