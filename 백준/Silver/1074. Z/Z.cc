#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;
int cnt=0;
int r, c;

void search(int row, int col,int s) {
	if (row == r&& col == c) {
		cout << cnt << endl;
		return;
	}
	if (row<=r&&r<row+s&&col<=c&&c<col+s) {
		search(row, col, s / 2);
		search(row, col + s / 2, s / 2);
		search(row+s/2, col, s / 2);
		search(row+s/2, col+s/2, s / 2);
	}
	else {
		cnt = cnt + s * s;
	}
	
}

int main() {
	int N;
	cin >> N >> r >> c;
	int num = pow(2, N);
	search(0, 0, num);
	return 0;
}