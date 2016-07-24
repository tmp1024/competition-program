#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string changex(string a, char b)
{
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'X') {
			a[i] = b;
		}
	}

	return a;
}

string strplus(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.length() != b.length()) {
		if (a.length() < b.length()) {
			a.push_back('0');
		}
		else {
			b.push_back('0');
		}
	}

	string c;
	for (int i = 0; i < a.length(); i++) {
		c.push_back('0');
	}

	int n = 0;
	for (int i = 0; i < a.length(); i++) {
		if (n + a[i] - '0' + b[i] - '0' <= 9) {
			c[i] = a[i] + b[i] - '0' + n;
			n = 0;
		}
		else {
			c[i] = a[i] + b[i] - '0' - 10 + n;
			n = 1;
		}
	}

	if (n == 1) {
		c.push_back('1');
	}
	reverse(c.begin(), c.end());

	return c;
}

int main()
{
	string in;
	while (cin >> in) {
		int plus, equal;
		bool zeroflag = false;
		if (in[0] == 'X') zeroflag = true;
		for (int i = 0; i < in.length(); i++) {
			if (in[i] == '+') {
				plus = i;
				if (in[i + 1] == 'X') {
					zeroflag = true;
				}
			}
			else if (in[i] == '=') {
				equal = i;
				if (in[i + 1] == 'X') {
					zeroflag = true;
				}
			}
		}

		string num1, num2, num3;
		num1 = in.substr(0, plus);
		num2 = in.substr(plus + 1, equal - plus - 1);
		num3 = in.substr(equal + 1);

		bool flag = false;
		string a, b, c;
		for (int i = 0; i <= 9; i++){
			// if (i == 0 && zeroflag) continue;
			a = changex(num1, (char)i + '0');
			b = changex(num2, (char)i + '0');
			c = changex(num3, (char)i + '0');

			if (strplus(a, b) == c) {
				cout << i << endl;
				flag = true;
				break;
			}
		}

		if (!flag) {
			cout << "NA" << endl;
		}
	}

	return 0;
}