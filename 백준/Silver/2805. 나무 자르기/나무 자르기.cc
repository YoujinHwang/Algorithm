#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        ll x;
        cin>>x;
        tree.push_back(x);
    }
    sort(tree.begin(),tree.end());
    
    int st=0;
    int en=tree[n-1];
    while(st<en) {
        ll sum=0;
        int mid=(st+en+1)/2;
        for(int i=0;i<n;i++) {
            int dif=tree[i]-mid;
            if(dif>0) sum+=dif;
        }
        if(sum>=m) st=mid;
        else en=mid-1;
    }
    cout<<st;

}