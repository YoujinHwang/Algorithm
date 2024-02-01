#include <bits/stdc++.h>
using namespace std;

int main() {
//	char c;
	string str;
	
	

	while (1) {
		bool isOkay = true;
		stack<char> s;
		getline(cin, str);
	//	if (c == '.') {
		//	cout << "yes" << '\n';
			//break;
	//	}
		if (str[0] == '.') {
			//cout << "yes" << '\n';
			return 0;
		}
		for (char c:str) {
		
//		while (cin>>c && c != '.') {
			if (c == '(' || c == '[') {
				s.push(c);
			}
			else if (c == ')') {
				if (!s.empty()) {
					if (s.top() == '(') {
						s.pop();
					}
					else {
						isOkay = false;
//						break;
						//cout << "no" << '\n';
						
					}
				}
				else {
					isOkay = false;
//					break;
				}
					
				
			}
			else if (c == ']') {
				if (!s.empty()) {
					if (s.top() == '[') {
						s.pop();
					}
					else {
						isOkay = false;
//						break;
						//cout << "no" << '\n';
						
					}
				}
				else {
					isOkay = false;
//					break;
				}
					
				
			}
			//cin>>c;
		}
		if (s.empty() && isOkay) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
			
		
	}
}
