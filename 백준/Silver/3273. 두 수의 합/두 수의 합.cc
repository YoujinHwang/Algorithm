#include<iostream>
#include<algorithm>
using namespace std;
int arr[2000001];

int main() {
	int n,x,cnt=0;
	int a;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a] = 1;
	}
	cin >> x;
	for (int i = 1; i < x/2+1; i++) {
		int num = x - i;
		if (arr[i] == 1 && arr[num] == 1) {
            if(i!=num)
			    cnt++;

		}
	}
	cout << cnt;
}