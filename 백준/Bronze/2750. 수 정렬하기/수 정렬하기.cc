#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int temp[1000];

void merge(int st, int en) {
	int mid = (st + en) / 2;
	int aidx = st;
	int bidx = mid;
	for (int i = st; i < en; i++) {
		if (aidx == mid) temp[i] = arr[bidx++];
		else if (bidx == en)temp[i] = arr[aidx++];
		else if(arr[aidx]<arr[bidx]) temp[i] = arr[aidx++];
		else temp[i] = arr[bidx++];
	}
	for (int i = st; i < en; i++) {
		arr[i] = temp[i];
	}
}

void mergeSort(int st, int en) {
	int mid = (st + en) / 2;
	if (en == st + 1) return;
	mergeSort(st, mid);
	mergeSort(mid, en);
	merge(st, en);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(0, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	
}