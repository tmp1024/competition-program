#include <cstdio>
#include <iostream>
#include <cctype>
#include <string>

typedef std::string::const_iterator State;

int expression(State&);
int term(State&);
int factor(State&);
int number(State&);

int expression(State &begin)
{
	int ret = term(begin);

	for (;;) {
		if (*begin == '+') {
			begin++;
			ret += term(begin);
		}
		else if (*begin == '-') {
			begin++;
			ret -= term(begin);
		}
		else {
			break;
		}
	}

	return ret;
}

int term(State &begin)
{
	int ret = factor(begin);

	for (;;) {
		if (*begin == '*') {
			begin++;
			ret *= factor(begin);
		}
		else if (*begin == '/') {
			begin++;
			ret /= factor(begin);
		}
		else {
			break;
		}
	}
	
	return ret;
}

int factor(State &begin)
{
	if (*begin == '(') {
		begin++;
		int ret = expression(begin);
		begin++;
		return ret;
	}
	else {
		return number(begin);
	}
}

int number(State &begin)
{
	int ret = 0;

	while (isdigit(*begin)) {
		ret *= 10;
		ret += *begin - '0';
		begin++;
	}

	return ret;
}

int main(void)
{
	int N;
	std::cin >> N;
	std::cin.ignore();

	for (int i = 0; i < N; i++) {
		std::string s;
		std::getline(std::cin, s);

		State begin = s.begin();
		int ans = expression(begin);
		std::cout << ans << std::endl;
	}

	return 0;
}