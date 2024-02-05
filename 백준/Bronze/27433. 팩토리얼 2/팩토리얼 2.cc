#include <bits/stdc++.h>
using namespace std;
long long factorial(int);

int main() {
	int N;
	cin >> N;
	long long result = factorial(N);
	cout << result;
}
long long factorial(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) return 1;
	else return n * factorial(n - 1);

}
