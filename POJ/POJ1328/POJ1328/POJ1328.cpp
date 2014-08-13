/*
 * http://poj.org/problem?id=1328
 */

#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int xg[1100];
int yg[1100];
int counter = 1;
int n, d;
bool check[1100];

int solve()
{
	set<pair< double, int > >right, left;
	set<int> cur;

	for (int i = 0; i < n; i++){
		check[i] = false;
	}

	for (int i = 0; i < n; i++){
		cin >> xg[i] >> yg[i];
	}

	for (int i = 0; i < n; i++){
		if (abs((double)yg[i]) > d){
			cout << "Case " << counter << ": ";
			cout << "-1" << endl;
			counter++;
			return 0;
		}
		left.insert(make_pair((double)xg[i] - sqrt(d * d - (double)yg[i] * yg[i]), i));
		right.insert(make_pair((double)xg[i] + sqrt(d * d - (double)yg[i] * yg[i]), i));
	}

	int ans = 0;
	while (!right.empty()){
		if (!left.empty() && left.begin()->first <= right.begin()->first){
			cur.insert(left.begin()->second);
			left.erase(left.begin());
		}
		else {
			int tmp = right.begin()->second;
			if (!check[tmp]){
				ans++;
				for (set<int>::iterator it = cur.begin(); it != cur.end(); it++){
					check[*it] = true;
				}
			}
			cur.erase(tmp);
			right.erase(right.begin());
		}
	}

	cout << "Case " << counter << ": ";
	cout << ans << endl;
	counter++;

	return ans;
}

int main()
{
	while (cin >> n >> d){
		if (n == 0 && d == 0){
			break;
		}

		solve();
	}

	return 0;
}