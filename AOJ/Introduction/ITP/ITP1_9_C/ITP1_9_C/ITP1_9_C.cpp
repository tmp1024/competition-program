#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int n;
	int taro = 0;
	int hanako = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (a < b) hanako += 3;
		if (a > b) taro += 3;
		if (a == b) taro++, hanako++;
	}
	cout << taro << " " << hanako << endl;

	return 0;
}