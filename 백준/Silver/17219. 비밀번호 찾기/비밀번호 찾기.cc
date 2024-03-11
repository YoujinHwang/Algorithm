#include <bits/stdc++.h>
using namespace std;
map<string,string> ma;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(n--) {
        string addr;
        string pw;
        string line;
        cin>>addr>>pw;
        ma.insert({addr,pw});
    }
    while(m--) {
        string key;
        cin>>key;
        cout<<ma[key]<<'\n';
    }
}