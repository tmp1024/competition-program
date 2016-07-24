#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int i, j, key;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            cout << A[j] << " ";
        }
        cout << A[n - 1] << endl;
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    for (j = 0; j < n - 1; j++) {
        cout << A[j] << " ";
    }
    cout << A[n - 1] << endl;
 
    return 0;
}
