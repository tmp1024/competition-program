#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    vector<pair<int, pair<int, int> > > d;
    int n, ans;

    while (scanf("%d,%d", &n, &ans)) {
        if (n == 0 && ans == 0) {
            break;
        }
        else {
            d.push_back(make_pair(ans, make_pair(n, 0)));
        }
    }

    sort(d.begin(), d.end(), greater<pair<int, pair<int, int> > >());

    vector<pair<int, pair<int, int> > >::iterator d_it = d.begin();
    d_it->second.second = 1;
    while (d_it != d.end()) {
        if (d_it->first == (d_it-1)->first) {
            d_it->second.second = (d_it-1)->second.second;
        }
        else {
            d_it->second.second = (d_it-1)->second.second + 1;
        }
        d_it++;
    }

    int inq;
    while (cin >> inq) {
        d_it = d.begin();
        while (d_it != d.end()) {
            if (d_it->second.first == inq) {
                cout << d_it->second.second << endl;
                break;
            }
            d_it++;
        }
    }
}
