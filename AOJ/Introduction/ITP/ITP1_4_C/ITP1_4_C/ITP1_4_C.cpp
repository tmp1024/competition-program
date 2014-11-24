#include <iostream>
#include <cstdio>

#pragma warning (disable:4996)

using namespace std;

int main()
{
	int a, b;
	char op;

	while (scanf("%d %c %d", &a, &op, &b)) {
		if (op == '?') break;
		else if (op == '+') {
			cout << a + b << endl;
		}
		else if (op == '-') {
			cout << a - b << endl;
		}
		else if (op == '*') {
			cout << a * b << endl;
		}
		else if (op == '/') {
			cout << a / b << endl;
		}
	}

	return 0;
}