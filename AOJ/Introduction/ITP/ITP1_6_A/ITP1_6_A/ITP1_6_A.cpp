#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vc;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vc.push_back(tmp);
	}
	reverse(begin(vc), end(vc));

	for (int i = 0; i < n-1; i++) {
		cout << vc[i] << " ";
	}
	cout << vc[n - 1] << endl;

	return 0;
}