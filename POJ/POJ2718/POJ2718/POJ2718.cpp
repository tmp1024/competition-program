/*
 * http://poj.org/problem?id=2718
 *
 * 注意
 *  next_permutationを使う前には、ソートをしなくてはならない
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string str;

	cin >> n;
	cin.ignore();

	while (n--){
		int ans = 1000000000;

		getline(cin, str);

		string::iterator remove_it = remove(str.begin(), str.end(), ' ');
		str.erase(remove_it, str.end());

		int slen = str.length();

		int num[10];

		for (int i = 0; i < slen; i++){
			num[i] = str[i] - '0';
		}

		sort(num, num + slen);

		do {
			if (num[0] == 0 || num[slen / 2] == 0){
				continue;
			}

			int num1 = num[0];
			int num2 = num[slen / 2];
			
			for (int i = 1; i < (slen / 2); i++){
				num1 = num1 * 10 + num[i];
			}
			for (int i = slen-1; i > (slen / 2); i--){
				num2 = num2 * 10 + num[i];
			}
			ans = min(ans, abs(num1 - num2));
		} while (next_permutation(num, num + slen));

		cout << ans << endl;
	}

	return 0;
}