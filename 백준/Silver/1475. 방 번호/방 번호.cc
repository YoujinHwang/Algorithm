#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int num[10] = { 0, };
	while (N != 0) {
		int s = N % 10;
		num[s]++;
		N /= 10;
	}
	int Max, ind, max2;
	int res = 0;
	Max = num[0];
	max2 = num[0];
	for (int i = 0; i < 10; i++) {
		if (num[i] > Max) {
			Max = num[i];
			ind = i;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)
			continue;
		if (num[i] > max2)
			max2 = num[i];
	}
	//cout << max2 << "\n";

	if (ind == 6 || ind == 9) {
		int add = num[6] + num[9];
		res = add / 2 + add % 2;
	}
	//cout << res << "\n";
	Max = max(res, max2);
	cout << Max;
	
}