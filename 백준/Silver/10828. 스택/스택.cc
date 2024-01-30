#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct stack {
    int arr[10000];
	int top;
	void init() {
		top = -1;
	}
	void push(int num) {
		top++;
		arr[top] = num;
	}
	int pop() {
		if (top == -1) {
			return -1;
		}

		int last = arr[top];
		top--;
		return last;
	}
	int size() {
		return top + 1;
	}
	int isempty() {
		if (top == -1) {
			return 1;
		}

		else {
			return 0;
		}

	}
	int tops() {
		if (top == -1) {
			return -1;
		}

		else {
			return arr[top];
		}

	}


};

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0), cout.tie(0);
	int n;
	int newn;
	stack s;
	s.init();
	string order;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		
		cin >> order;
		if (order == "push") {
			cin >> newn;
			s.push(newn);
		}
		else if (order == "pop") {
			cout << s.pop() << endl;
		}
		else if (order == "size") {
			cout<<s.size()<<endl;
		}
		else if (order == "empty") {
			cout << s.isempty() << endl;
		}
		else if (order == "top") {
			cout << s.tops() << endl;
		}
		
	}
	
}