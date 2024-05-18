#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> maxH;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(x>0) maxH.push(x);
        else if(x==0) {
            if(!maxH.empty()) {
                cout<<maxH.top()<<'\n';
                maxH.pop();
            }
            else cout<<0<<'\n';
        }
    }
}