/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0121
 */

#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> mp;

int dx[] = { 1, 4, -1, -4 };

int main()
{
	queue<string> que;
	string str;

	que.push("01234567");

	while (!que.empty()){
		str = que.front(); que.pop();

		int zero = str.find('0');

		for (int i = 0; i < 4; i++){
			int nzero = zero + dx[i];

			if ((0 <= nzero && nzero <= 7) && !((zero == 3 && nzero == 4) || (zero == 4 && nzero == 3))){
				string str2 = str;
				swap(str2[zero], str2[nzero]);

				if (mp.find(str2) == mp.end()){
					mp[str2] = mp[str] + 1;
					que.push(str2);
				}
			}
		}
	}

	while (getline(cin, str)){
		string::iterator remove_it = remove(str.begin(), str.end(), ' ');
		str.erase(remove_it, str.end());

		cout << mp[str] << endl;
	}

	return 0;
}