#include <bits/stdc++.h>
using namespace std;
int N, S;
int cnt;
int arr[20];

void part(int n, int curSum) {
	if (n==N) {
		if (curSum == S) {
			cnt++;
		}
		return;
	}
	part(n + 1, curSum + arr[n]);
	part(n + 1, curSum);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	part(0,0);
	if (S == 0) cnt--;
	cout << cnt;
}