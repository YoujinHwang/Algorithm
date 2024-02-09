#include <bits/stdc++.h>
using namespace std;
int arr[15][15];
bool isHere[15];

int N;
int cnt;
bool diag1[30], diag2[30]; // 대각선 체크

void place(int k) {
	if (k == N) {
		cnt++;
		return;
	}
	for (int j = 0; j < N; j++) {
		if (!isHere[j] && !diag1[k + j] && !diag2[k - j + N ]) {
			isHere[j] = diag1[k + j] = diag2[k - j + N ] = true;
			place(k + 1);
			isHere[j] = diag1[k + j] = diag2[k - j + N ] = false;
		}
	}
}



int main() {
	cin >> N;
	place(0);
	cout << cnt;
	return 0;
}