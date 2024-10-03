#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	string num;
	cin >> num;
	stack<char> s;
	int cnt = K; 
	for (int i = 0; i < N; i++) {
		
		while (!s.empty() && cnt > 0 && num[i] > s.top()) {

			s.pop();
			cnt--;
		}
		s.push(num[i]);
	}
	vector<char> ans;
	while (!s.empty()) {
		ans.push_back(s.top()); 
		s.pop();
	}
	reverse(ans.begin(), ans.end()); 
	for (int i = 0; i < N - K; i++) {
		cout << ans[i]; 
	}
}