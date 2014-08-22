/*
 * http://poj.org/problem?id=1017
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int p[6];

	while (true){
		for (int i = 0; i < 6; i++){
			cin >> p[i];
		}

		int ans = 0;
		int s1 = 0;
		int s2 = 0;

		// 6*6のパケット
		ans += p[5];

		// 5*5のパケット
		ans += p[4];
		s1 += p[4] * 11;

		// 4*4のパケット
		ans += p[3];
		s2 += p[3] * 5;

		// 3*3のパケット
		ans += (p[2] + 3) / 4;

		switch (p[2] % 4){
			case 0:
				break;
			case 1:
				s1 += 7; s2 += 5;
				break;
			case 2:
				s1 += 6; s2 += 3;
				break;
			case 3:
				s1 += 5; s2 += 1;
				break;
		}

		// 2*2のパケット
		if (s2 < p[1]){
			p[1] -= s2;
		}
		else {
			s1 += (s2 - p[1]) * 4;
			p[1] = 0;
		}
		ans += (p[1] + 8) / 9;
		s1 += (9 - p[1] % 9) % 9 * 4;

		// 1*1のパケット
		if (s1 < p[0]){
			p[0] -= s1;
		}
		else {
			p[0] = 0;
		}
		ans += (p[0] + 35) / 36;

		if (ans == 0) break;

		cout << ans << endl;
	}

	return 0;
}