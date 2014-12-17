#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string x;
	while (cin >> x && x != "0") {
		int sum = 0;
		for (int i = 0; i < x.size(); i++) {
			sum += x[i] - '0';
		}
		cout << sum << endl;
	}

	return 0;
}