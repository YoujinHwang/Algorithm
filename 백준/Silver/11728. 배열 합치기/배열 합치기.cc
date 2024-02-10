#include <bits/stdc++.h>
using namespace std;
int arr1[1000000];
int arr2[1000000];
int arr3[2000000];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr1[i];
	for (int i = 0; i < M; i++)
		cin >> arr2[i];
	int a=0, b = 0;
	int k=0;
	while (a < N && b < M) {
		if (arr1[a] <= arr2[b])
			arr3[k++] = arr1[a++];
		else
			arr3[k++] = arr2[b++];
	}
	if (a == N) {
		while(b<M)
			arr3[k++] = arr2[b++];
	}
	else if (b == M) {
		while(a<N)
			arr3[k++] = arr1[a++];
	}
	for (int i = 0; i < N + M; i++)
		cout << arr3[i]<<' ';
}