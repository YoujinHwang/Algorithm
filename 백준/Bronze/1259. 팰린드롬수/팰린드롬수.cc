#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(1) {
        cin>>n;
        if(!n) return 0;
        string str=to_string(n);
        int len=str.size();
        len--;
        int i=0;
        while(len>i&&str[i]==str[len]) {
            i++;
            len--;
        }
        if(len<=i) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
}