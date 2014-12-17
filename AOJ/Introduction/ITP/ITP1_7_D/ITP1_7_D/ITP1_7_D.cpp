#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n, m, l;
	cin >> n >> m >> l;
	vector<vector<int> > nm(n, vector<int>(m));
	vector<vector<int> > ml(m, vector<int>(l));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nm[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < l; j++) {
			cin >> ml[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			long long int sum = 0;
			for (int k = 0; k < m; k++) {
				sum += nm[i][k] * ml[k][j];
			}
			if (j == l - 1) {
				cout << sum << endl;
			}
			else {
				cout << sum << " ";
			}
		}
	}

	return 0;
}