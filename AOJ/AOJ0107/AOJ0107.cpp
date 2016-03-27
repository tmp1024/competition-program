#include <cstdio>
#include <iostream>
#include <cmath>

#pragma warning (disable:4996)

int main()
{
	int l, w, h;

	while (std::scanf("%d %d %d", &l, &w, &h) != EOF){
		if (l == 0 && w == 0 && h == 0){
			break;
		}

		double r[3];
		r[0] = std::sqrt((l * l) + (w * w));
		r[1] = std::sqrt((w * w) + (h * h));
		r[2] = std::sqrt((h * h) + (l * l));

		int n;
		std::scanf("%d", &n);

		int R;
		bool flag = false;
		for (int i = 0; i < n; i++){
			std::scanf("%d", &R);
			flag = false;
			for (int j = 0; j < 3; j++){
				if (r[j] < (2 * R)){
					flag = true;
				}
			}
			if (flag){
				std::printf("OK\n");
			}
			else {
				std::printf("NA\n");
			}
		}
	}

	return 0;
}