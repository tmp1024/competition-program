/*
 * http://poj.org/problem?id=1862
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<double> m;

	for (int i = 0; i < n; i++){
		double tmp;
		cin >> tmp;
		m.push(tmp);
	}

	while (m.size() != 1){
		double a = m.top(); m.pop();
		double b = m.top(); m.pop();

		m.push(2 * sqrt(a * b));
	}

	cout << fixed;
	cout << setprecision(3) << m.top() << endl;

	return 0;
}