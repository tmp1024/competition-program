#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool validcontain(pair<int, pair<int, int> >wall, int c, int d)
{
	if ((c - wall.first) * (c - wall.first) + (d - wall.second.first) * (d - wall.second.first) < wall.second.second * wall.second.second) {
		return true;
	}

	return false;
}

int main()
{
	int n, m;
	while (cin >> n && n) {

		vector< pair<int, pair<int, int> > > wall(n);
		for (int i = 0; i < n; i++) {
			cin >> wall[i].first >> wall[i].second.first >> wall[i].second.second;
		}

		cin >> m;

		int tx, ty, sx, sy;
		for (int i = 0; i < m; i++) {
			cin >> tx >> ty >> sx >> sy;

			bool flag = false;

			for (int j = 0; j < n; j++) {
				if ((validcontain(wall[j], tx, ty) == true) && (validcontain(wall[j], sx, sy) == true)) {
					continue;
				}

				int vex1 = wall[j].first - tx;
				int vey1 = wall[j].second.first - ty;
				int vex2 = sx - tx;
				int vey2 = sy - ty;

				int x = wall[j].first;
				int y = wall[j].second.first;
				int r = wall[j].second.second;
				int n1 = vex1 * vex2 + vey1 * vey2;
				int n2 = vex2 * vex2 + vey2 * vey2;
				int n3 = vex1 * vex1 + vey1 * vey1;
				if (n1 < 0) {
					if ((tx - x)*(tx - x) + (ty - y)*(ty - y) <= r*r) {
						flag = true;
						break;
					}
				}
				else if (n2 < n1) {
					if ((sx - x)*(sx - x) + (sy - y)*(sy - y) <= r*r) {
						flag = true;
						break;
					}
				}
				else {
					if (n2 <= 0) {
						if (n3*n2 - n1*n1 >= r*r*n2) {
							flag = true;
							break;
						}
					}
					else {
						if (n3*n2 - n1*n1 <= r*r*n2) {
							flag = true;
							break;
						}
					}
				}
			}

			if (flag) {
				cout << "Safe" << endl;
			}
			else {
				cout << "Danger" << endl;
			}
		}
	}

	return 0;
}