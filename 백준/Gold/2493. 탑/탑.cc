#include <iostream>
#include <stack>
using namespace std;
int vis[500001];
int arr[500001];
struct Node {
	int num;
	int ind;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	
	stack<Node> s1;
	stack<Node> s2;

	for (int i = 1; i <= N; i++) {
		int h;
		cin >> h;
		s1.push({ h,i });
	}
	while (!s1.empty()) {
		Node cur = s1.top();
		s1.pop();
		while (!s2.empty()) {
			Node tar = s2.top();
			if (cur.num >= tar.num) {
				vis[tar.ind] = cur.ind;
				s2.pop();
			}
			else break;
		}
		s2.push({ cur });

	}
	for (int i = 1; i <= N; i++) {
		cout << vis[i] << ' ';
	}
}