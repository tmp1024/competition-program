/*
 * http://poj.org/problem?id=2376
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

P pi[25000];

int main()
{
	int N, T;

	cin >> N >> T;

	for (int i = 0; i < N; i++){
		cin >> pi[i].first >> pi[i].second;
	}

	sort(pi, pi + N);

	int ans = 0;
	int current = 0;
	int m;
	int cv = 0;
	for (; current < N && cv < T;){
		m = 0;
		for (; current < N && pi[current].first <= cv+1; current++){
			m = max(m, pi[current].second);
		}
		if (m == 0){
			break;
		}
		cv = m;
		ans++;
	}

	cout << (cv >= T ? ans : -1) << endl;

	return 0;
}