#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int h, w;

	while (cin >> h >> w) {
		if (h == 0 && w == 0) break;

		for (int i = 0; i < w; i++) {
			putchar('#');
		}
		putchar('\n');
		for (int i = 1; i < h - 1; i++) {
			for (int j = 0; j < w; j++) {
				if (j == 0 || j == w-1) {
					putchar('#');
				}
				else {
					putchar('.');
				}
			}
			putchar('\n');
		}
		for (int i = 0; i < w; i++) {
			putchar('#');
		}
		putchar('\n');

		putchar('\n');
	}

	return 0;
}