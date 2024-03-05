#include <bits/stdc++.h>
using namespace std;
vector<int> p;
int cnt[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        p.push_back(x);
    }
    sort(p.begin(),p.end());
    cnt[0]=p[0];
    for(int i=1;i<n;i++) {
        cnt[i]=cnt[i-1]+p[i];
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        ans+=cnt[i];
    }
    cout<<ans<<'\n';
}