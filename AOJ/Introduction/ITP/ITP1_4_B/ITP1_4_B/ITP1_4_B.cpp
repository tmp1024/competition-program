#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdio>

using namespace std;

int main()
{
	double r;
	cin >> r;
	printf("%f %f\n", r*r*M_PI, r * 2 * M_PI);

	return 0;
}