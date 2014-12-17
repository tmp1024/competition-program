#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;
	vector<vector<int> > vc(r + 1, vector<int>(c + 1));
	for (int i = 0; i < r; i++) {
		int sum = 0;
		for (int j = 0; j < c; j++) {
			cin >> vc[i][j];
			sum += vc[i][j];
		}
		vc[i][c] = sum;
	}
	for (int i = 0; i < c; i++) {
		int sum = 0;
		for (int j = 0; j < r; j++) {
			sum += vc[j][i];
		}
		vc[r][i] = sum;
	}
	int sum = 0;
	for (int i = 0; i < c; i++) {
		sum += vc[r][i];
	}
	vc[r][c] = sum;
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j < c; j++) {
			cout << vc[i][j] << " ";
		}
		cout << vc[i][c] << endl;
	}

	return 0;
}