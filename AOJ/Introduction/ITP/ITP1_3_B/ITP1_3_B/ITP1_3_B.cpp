#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int x;
	int counter = 1;

	while (true) {
		cin >> x;
		if (x == 0) break;
		printf("Case %d: %d\n", counter, x);
		counter++;
	}

	return 0;
}