#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,x,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
        bool isPrime=true;
		cin >> x;
		if (x == 1) continue;
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				isPrime = false;
				break;
			}
			
		}
		if(isPrime) cnt += 1;
	}
	cout << cnt << '\n';
}