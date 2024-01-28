#include<iostream>
#include<algorithm>
using namespace std;
int arr[2000001];
int arr2[1000000];

int main() {
	int n,x,cnt=0;
	int a;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a] = 1;
		arr2[i] = a;
	}
	cin >> x;
/*	for (int i = 1; i < x / 2; i++) {
		int num = x - i;
		if (arr[i] == 1 && arr[num] == 1) {
			cnt++;

		}
	}*/
	for (int i = 0; i < n; i++) {
		int num = x - arr2[i];
		if (arr[num] == 1)
			cnt++;
	}
	cout << cnt/2;
}