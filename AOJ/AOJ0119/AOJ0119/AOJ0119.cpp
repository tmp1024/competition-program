#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int m, n;

	cin >> m;
	cin >> n;

	map<int, vector<int> > evi;
	vector<int> count(m);
	vector<bool> used(m);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		evi[a].push_back(b);
		count[b]++;
	}

	used[1] = true;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (!used[j] && count[j] == 0) {
				used[j] = true;
				cout << j + 1 << endl;
				for (int k = 0; k < evi[j].size(); k++) {
					count[evi[j][k]]--;
				}
			}
		}
	}

	cout << 2 << endl;

	getchar();
	getchar();

	return 0;
}