#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, res;
	cin >> a >> b >> c;
	res = a * b * c;
	int num[10] = { 0, };
	while (1) {
		
		int n = res % 10;
		res = res / 10;
		num[n]++;
		if (res == 0)
			break;
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << "\n";
	}
}