#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int N, K, tot=1,di=1;
	cin >> N >> K;
	for (int i=0; i < K; i++) {
		tot *= (N - i);
		di *= (K - i);
	}
	int ans=tot / di;
	cout << ans << endl;
	return 0;
}