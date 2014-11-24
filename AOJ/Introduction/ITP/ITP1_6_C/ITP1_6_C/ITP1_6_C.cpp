#include <iostream>
#include <cstdio>

using namespace std;

int buil[4][3][10];

int main()
{
	int n;
	cin >> n;
	while (n--) {
		int b, f, r, v;
		cin >> b >> f >> r >> v;
		b--; f--; r--;
		buil[b][f][r] += v;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++) {
				cout << " " << buil[i][j][k];
			}
			putchar('\n');
		}
		if (i != 3) {
			cout << "####################" << endl;
		}
	}

	return 0;
}