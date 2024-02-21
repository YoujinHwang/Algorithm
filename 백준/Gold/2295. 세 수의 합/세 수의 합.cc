#include <bits/stdc++.h>
using namespace std;
int U[1000];
vector<int> U2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> U[i];
	}
	sort(U, U + n);
	
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			U2.push_back(U[i] + U[j]);
		}
	}
	sort(U2.begin(), U2.end());
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			int x = U[i] - U[j];
			if (binary_search(U2.begin(), U2.end(), x)) {
				cout << U[i] << '\n';
				return 0;
			}
			
		}
		
	}
}