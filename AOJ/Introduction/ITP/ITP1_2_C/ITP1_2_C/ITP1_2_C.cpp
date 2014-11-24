#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	if (c < b) swap(c, b);
	if (b < a) swap(b, a);
	if (c < b) swap(c, b);

	cout << a << " " << b << " " << c << endl;

	return 0;
}