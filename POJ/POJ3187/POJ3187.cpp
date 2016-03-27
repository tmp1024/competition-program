/*
 * http://poj.org/problem?id=3187
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int com[11][11];

int main()
{
	int N, target;
	vector<int> arr;

	cin >> N >> target;

	for (int i = 0; i <= 10; i++){
		com[i][0] = 1;
		com[i][i] = 1;
	}

	for (int i = 1; i <= 10; i++){
		for (int j = 1; j < i; j++){
			com[i][j] = com[i - 1][j] + com[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= N; i++){
		arr.push_back(i);
	}

	do {
		int sum = 0;
		for (int i = 0; i < N; i++){
			sum += arr[i] * com[N-1][i];
		}
		if (sum == target){
			for (int i = 0; i < N; i++){
				cout << arr[i];
				if (i != N - 1){
					cout << " ";
				}
			}
			cout << endl;
			break;
		}
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}