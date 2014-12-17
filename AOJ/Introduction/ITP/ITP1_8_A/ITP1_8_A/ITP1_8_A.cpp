#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string in;
	getline(cin, in);
	string uin = in;
	string lin = in;
	transform(uin.begin(), uin.end(), uin.begin(), ::toupper);
	transform(lin.begin(), lin.end(), lin.begin(), ::tolower);
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == uin[i]) {
			cout << lin[i];
		}
		else {
			cout << uin[i];
		}
	}
	cout << endl;

	return 0;
}