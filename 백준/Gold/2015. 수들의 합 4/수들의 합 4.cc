#include<iostream>
#include <unordered_map>
using namespace std;
int arr[200001];
long long DAT[200001];
unordered_map<long long, long long> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	long long cnt = 0;
	m[0] = 1;
	for (int i = 1; i <= N; i++) {
		DAT[i] = DAT[i - 1] + arr[i];
		cnt += m[DAT[i] - K]; //이렇게 차를 기준으로 생각하는게 어려웠음!!
		m[DAT[i]]++;
	}

	cout << cnt;
}