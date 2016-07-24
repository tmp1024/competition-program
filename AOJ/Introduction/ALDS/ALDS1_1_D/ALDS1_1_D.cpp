#include <iostream>
#include <cstdio>
#include <algorithm>
 
#pragma warning(disable:4996)
 
using namespace std;
 
int main()
{
    int n;
    int min_r;
    cin >> n >> min_r;
    int r, tmp, ans = -1000000000;
    for (int i = 1; i < n; i++) {
        cin >> r;
        tmp = r - min_r;
        if (tmp > ans) ans = tmp;
        min_r = min(r, min_r);
    }
    cout << ans << endl;
 
    return 0;
}
