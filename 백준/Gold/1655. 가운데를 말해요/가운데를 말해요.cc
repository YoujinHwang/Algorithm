#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<>> Min;
	priority_queue<int> Max;
	int x;
	cin >> x;
	Min.push(x);
	cout << x << '\n';
	for (int i = 2; i <= N; i++) {
		cin >> x;
		int tmp=Min.top();
		if (x >= tmp) {
			Min.push(x);
		}
		else {
			Max.push(x);
		}
		if (Min.size() > Max.size()) {
			if (Min.size() - Max.size() >= 2) {
				Max.push(Min.top());
				Min.pop();
			}
			else cout << Min.top() << '\n';
		}
		
		else if(Min.size() < Max.size()) {
			if (Max.size() - Min.size() >= 2) {
				Min.push(Max.top());
				Max.pop();
			}
			else cout << Max.top() << '\n';
		}
		if (Min.size() == Max.size()) {
			cout << min(Min.top(), Max.top()) << '\n';
		}
	}
}