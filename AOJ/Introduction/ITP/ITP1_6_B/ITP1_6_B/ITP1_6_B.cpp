#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool card[4][13];

int main()
{
	int n;
	cin >> n;
	char suit;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> suit >> tmp;
		// cout << suit << " " << tmp << endl;
		switch (suit) {
		case 'S': card[0][tmp-1] = true; break;
		case 'H': card[1][tmp-1] = true; break;
		case 'C': card[2][tmp-1] = true; break;
		case 'D': card[3][tmp-1] = true; break;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (!card[i][j]) {
				switch (i) {
				case 0: cout << 'S' << " " << j + 1 << endl; break;
				case 1: cout << 'H' << " " << j + 1 << endl; break;
				case 2: cout << 'C' << " " << j + 1 << endl; break;
				case 3: cout << 'D' << " " << j + 1 << endl; break;
				}
			}
		}
	}

	return 0;
}