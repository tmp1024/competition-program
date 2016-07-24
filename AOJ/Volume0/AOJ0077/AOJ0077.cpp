#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in;

    while (cin >> in) {
        for (int i = 0; i < in.length(); i++) {
            if (in[i] == '@') {
                for (int j = 0; j < in[i + 1] - '0'; j++) {
                    cout << in[i + 2];
                }
                i += 2;
            }
            else {
                cout << in[i];
            }
        }
        cout << endl;
    }

    return 0;
}