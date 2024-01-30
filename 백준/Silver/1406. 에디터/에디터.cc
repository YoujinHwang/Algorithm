#include <bits/stdc++.h>
using namespace std;

int main() {
	string input;
//	char s = ' ';
	int num;
	char order,alp;
	list<char> str;
	
	getline(cin, input);
	for (char ch : input) {
		str.push_back(ch);
		//t++;
	}
	list<char>::iterator t = str.end();
	
/*	while (s != '\n') {
		cin >> s;
		str.push_back(s);
	}*/
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> order;
		
		if (order == 'L') {
			if(t!=str.begin())
				t--;
			//cout << *t;
		}
		else if (order == 'D') {
			if(t!=str.end())
				t++;
			//cout << *t;
		}
		else if (order == 'B') {
			if (t != str.begin()) {
				t--;
				t=str.erase(t);
			}
			
			//cout << *t;
			
		}
		else if (order == 'P') {
			cin >> alp;
			str.insert(t, alp);
			//cout << *t;
		}
				
	}
	for (char ch : str)
		cout << ch;
}