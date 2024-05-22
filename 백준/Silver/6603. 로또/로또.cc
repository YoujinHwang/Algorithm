#include <iostream>
#include <vector>
using namespace std;
int ans[6];
int n;
bool vis[13];

void func(int cnt,int x,vector<int> v) {
    if(cnt==6) {
        for(int i=0;i<6;i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=x;i<n;i++) {
        if(!vis[i]) {
            ans[cnt]=v[i];
            vis[i]=true;
            func(cnt+1,i,v);
            vis[i]=false;
        }
    }
}

int main() {
    while(1) {
        cin>>n;
        if(n==0) return 0;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            v.push_back(x);
        }
        fill(vis,vis+n,false);
        func(0,0,v);
        cout<<'\n';
    }
}