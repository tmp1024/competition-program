#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	string in;

	map<char, string> trans;
	trans['A'] = "00000";
	trans['B'] = "00001";
	trans['C'] = "00010";
	trans['D'] = "00011";
	trans['E'] = "00100";
	trans['F'] = "00101";
	trans['G'] = "00110";
	trans['H'] = "00111";
	trans['I'] = "01000";
	trans['J'] = "01001";
	trans['K'] = "01010";
	trans['L'] = "01011";
	trans['M'] = "01100";
	trans['N'] = "01101";
	trans['O'] = "01110";
	trans['P'] = "01111";
	trans['Q'] = "10000";
	trans['R'] = "10001";
	trans['S'] = "10010";
	trans['T'] = "10011";
	trans['U'] = "10100";
	trans['V'] = "10101";
	trans['W'] = "10110";
	trans['X'] = "10111";
	trans['Y'] = "11000";
	trans['Z'] = "11001";
	trans[' '] = "11010";
	trans['.'] = "11011";
	trans[','] = "11100";
	trans['-'] = "11101";
	trans['\''] = "11110";
	trans['?'] = "11111";


	map<string, char> trans2;
	trans2["101"] = ' ';
	trans2["000000"] = '\'';
	trans2["000011"] = ',';
	trans2["10010001"] = '-';
	trans2["010001"] = '.';
	trans2["000001"] = '?';
	trans2["100101"] = 'A';
	trans2["10011010"] = 'B';
	trans2["0101"] = 'C';
	trans2["0001"] = 'D';
	trans2["110"] = 'E';
	trans2["01001"] = 'F';
	trans2["10011011"] = 'G';
	trans2["010000"] = 'H';
	trans2["0111"] = 'I';
	trans2["10011000"] = 'J';
	trans2["0110"] = 'K';
	trans2["00100"] = 'L';
	trans2["10011001"] = 'M';
	trans2["10011110"] = 'N';
	trans2["00101"] = 'O';
	trans2["111"] = 'P';
	trans2["10011111"] = 'Q';
	trans2["1000"] = 'R';
	trans2["00110"] = 'S';
	trans2["00111"] = 'T';
	trans2["10011100"] = 'U';
	trans2["10011101"] = 'V';
	trans2["000010"] = 'W';
	trans2["10010010"] = 'X';
	trans2["10010011"] = 'Y';
	trans2["10010000"] = 'Z';


	while (getline(cin, in) || !cin.eof()) {
		string str = "";

		for (int i = 0; i < in.size(); i++) {
			str += trans[in[i]];
		}

		string ans = "";
		string tmp = "";
		for (int i = 0; i < str.size(); i++) {
			tmp += str[i];
			if (trans2[tmp] != 0) {
				ans += trans2[tmp];
				tmp = "";
			}
		}
		cout << ans << endl;
	}
}