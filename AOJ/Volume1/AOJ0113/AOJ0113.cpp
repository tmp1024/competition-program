#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int p, q;

	while (cin >> p >> q) {
		int start = -1;
		vector<int> vc;
		map<int, int> mp;
		p *= 10;

		while (vc.size() <= 100) {
			if (mp[p]) {
				start = mp[p];
				break;
			}
			vc.push_back(p / q);
			mp[p] = vc.size();
			if (p % q == 0) break;
			p %= q;
			p *= 10;
		}

		int n = vc.size();
		for (int i = 0; i < n; i++) {
			cout << vc[i];
		}
		cout << endl;
		if (start >= 0) {
			start--;
			for (int i = 0; i < start; i++) {
				printf(" ");
			}
			for (int i = start; i < n; i++) {
				printf("^");
			}
			cout << endl;
		}
	}

	return 0;
}