/*
 * http://poj.org/problem?id=3190
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int counter[50000];

int main()
{
	cin >> N;
	
	priority_queue<pair<int, pair<int, int> > > qu1;

	int a, b;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		qu1.push(make_pair(-a, make_pair(-b, i)));
	}

	priority_queue<pair<int, int> > qu2;
	int ans = 0;

	while (!qu1.empty()){
		int a = -qu1.top().first, b = -qu1.top().second.first, i = qu1.top().second.second;
		qu1.pop();

		if (qu2.empty() || -qu2.top().first >= a){
			ans++;
			qu2.push(make_pair(-b, ans));
			counter[i] = ans;
		}
		else {
			counter[i] = qu2.top().second;
			qu2.pop();
			qu2.push(make_pair(-b, counter[i]));
		}
	}

	cout << ans << endl;
	for (int i = 0; i < N; i++){
		cout << counter[i] << endl;
	}


	return 0;
}