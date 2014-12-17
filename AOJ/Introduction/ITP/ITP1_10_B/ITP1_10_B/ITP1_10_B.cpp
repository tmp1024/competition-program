#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int a, b, C;
	cin >> a >> b >> C;
	double S, L, h;
	h = b * sin(C*3.1415926/180);
	S = h * a / 2;
	L = a + b +sqrt(a*a + b*b - 2 * a * b * cos(C*3.1415926/180));

	printf("%f\n%f\n%f\n", S, L, h);

	return 0;
}