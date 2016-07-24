#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
 
#pragma warning(disable:4996)
 
using namespace std;
 
bool isprime(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return x != 1;
}
 
int main()
{
    int n;
    scanf("%d", &n);
    int x;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (isprime(x)) counter++;
    }
    printf("%d\n", counter);
 
    return 0;
}
