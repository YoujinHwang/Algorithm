#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long powm(int A, int B, int C) {
	if (B == 0) return 1;
	long long ans = powm(A, B / 2, C);
	ans = ans * ans % C;
	if (B % 2) ans = ans * A % C;
	return ans;
}
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	long long a=powm(A, B, C);
	cout << a;
}