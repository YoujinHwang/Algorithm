#include <bits/stdc++.h>
using namespace std;
set<int> level[101];
int pro[100001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p,l;
    int m,x;
    string ord;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>p>>l;
        level[l].insert(p);
       pro[p]=l;
    }
    cin>>m;
    while(m--) {
        cin>>ord;
        if(ord=="recommend") {
            cin>>x;
            if(x==1) {
                for(int i=100;i>=1;i--) {
                    if(level[i].empty()) continue;
                    cout<<*prev(level[i].end())<<'\n';
                    break;
                }
            }
            else {
                for(int i=1;i<=100;i++) {
                    if(level[i].empty()) continue;
                    cout<<*level[i].begin()<<'\n';
                    break;
                }
            }
        }
        else if(ord=="add") {
            cin>>p>>l;
            level[l].insert(p);
            pro[p]=l;
        }
        else {
            cin>>p;
            int lev=pro[p];
            level[lev].erase(p);
        }
    }
}