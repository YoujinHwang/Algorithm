#include <bits/stdc++.h>
using namespace std;
#include <set>
set<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,x;
    cin>>m;
    while(m--) {
        string ord;
        cin>>ord;
        if(ord=="add") {
            cin>>x;
            s.insert(x);
        }
        else if(ord=="remove") {
            cin>>x;
            s.erase(x);
        }
        else if(ord=="check") {
            cin>>x;
            if(s.find(x)!=s.end()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(ord=="toggle") {
            cin>>x;
            if(s.find(x)!=s.end()) {
                s.erase(x);
            }
            else s.insert(x);
        }
        else if(ord=="all") {
            for(int i=1;i<=20;i++) {
                s.insert(i);
            }
        }
        else s.clear();
    }
}