#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	for (int i = 0; i < n; i++) {
		d1 += abs(x[i] - y[i]);
		d2 += (x[i] - y[i]) * (x[i] - y[i]);
		d3 += abs((x[i] - y[i])) * (x[i] - y[i]) * (x[i] - y[i]);
		d4 = max(d4, (double)abs(x[i] - y[i]));
	}
	d2 = sqrt(d2);
	d3 = pow(d3, 1.0/3.0);
	printf("%f\n%f\n%f\n%f\n", d1, d2, d3, d4);


	return 0;
}