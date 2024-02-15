#include <bits/stdc++.h>
using namespace std;
int d[301][4];
int stair[301];

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	d[1][3] = stair[1];
	d[2][1] = stair[2]; //초기화 해줘야함
	d[2][2] = stair[1] + stair[2]; //초기화 해줘야함
	d[2][3] = max(d[2][1],d[2][2]);
	for (int i = 3; i <= n; i++) {
	
		d[i][1] = d[i - 2][3] + stair[i];
		d[i][2] = d[i - 1][1] + stair[i]; //i번째 계단을 밟으려면 그 전에 연속으로 두개째여야 하므로 d[i-1][1]+stair[i]이여야 함!!(d[i-1][3]이면 안됨)
		d[i][3] = max(d[i][1], d[i][2]);
			
		
	}
	cout << d[n][3] << '\n';
}