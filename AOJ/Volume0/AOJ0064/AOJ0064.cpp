#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int sum = 0;
    string in;

    while (cin >> in) {
        for (int i = 0; i < in.length(); i++) {
            if (isdigit(in[i])) {
                string n;
                for (; isdigit(in[i]); i++) {
                    n += in[i];
                }
                sum += stoi(n);
            }
        }
    }
    cout << sum << endl;

    return 0;
}