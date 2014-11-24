#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	int d, r;
	double f;

	d = a / b;
	r = a % b;
	f = (double)a / b;

	printf("%d %d %f\n", d, r, f);

	return 0;
}