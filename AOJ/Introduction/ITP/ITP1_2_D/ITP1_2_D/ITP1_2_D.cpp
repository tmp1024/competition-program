#include <iostream>

using namespace std;

int main()
{
	int w, h, x, y, r;

	cin >> w >> h >> x >> y >> r;

	bool flag = true;
	if (x - r < 0 || w < x + r) {
		flag = false;
	}
	if (y - r < 0 || h < y + r) {
		flag = false;
	}

	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}