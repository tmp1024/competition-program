#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main()
{
	string in;
	map<string, char> mp;
	mp["11"] = 'a';
	mp["12"] = 'b';
	mp["13"] = 'c';
	mp["14"] = 'd';
	mp["15"] = 'e';
	mp["21"] = 'f';
	mp["22"] = 'g';
	mp["23"] = 'h';
	mp["24"] = 'i';
	mp["25"] = 'j';
	mp["31"] = 'k';
	mp["32"] = 'l';
	mp["33"] = 'm';
	mp["34"] = 'n';
	mp["35"] = 'o';
	mp["41"] = 'p';
	mp["42"] = 'q';
	mp["43"] = 'r';
	mp["44"] = 's';
	mp["45"] = 't';
	mp["51"] = 'u';
	mp["52"] = 'v';
	mp["53"] = 'w';
	mp["54"] = 'x';
	mp["55"] = 'y';
	mp["61"] = 'z';
	mp["62"] = '.';
	mp["63"] = '?';
	mp["64"] = '!';
	mp["65"] = ' ';


	while (cin >> in) {
		if (in.size() % 2) {
			cout << "NA" << endl;
			continue;
		}
		string ans = "";
		bool flag = true;
		for (int i = 0; i < in.size(); i += 2) {
			if ('1' <= in[i] && in[i] <= '6' && '1' <= in[i + 1] && in[i + 1] <= '5') {
				ans += mp[in.substr(i, 2)];
			}
			else {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << ans << endl;
		}
		else {
			cout << "NA" << endl;
		}
	}

	return 0;
}