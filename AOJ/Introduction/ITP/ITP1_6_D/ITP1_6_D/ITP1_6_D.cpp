#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > vc(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vc[i][j];
		}
	}
	vector<int> vc2(m);
	for (int i = 0; i < m; i++) {
		cin >> vc2[i];
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += vc[i][j] * vc2[j];
		}
		cout << sum << endl;
	}

	return 0;
}