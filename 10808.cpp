#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	string S;
	cin >> S;
	int alp[26] = { 0, };

	for (int i = 0; i < S.length(); i++)
	{
		alp[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alp[i] << ' ';
	}
	return 0;
}