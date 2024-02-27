#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>,greater<int>> pq;
    int n,x;
    int ans=0;
    cin>>n;
    while(n--) {
        cin>>x;
        pq.push(x);
    }
    while(pq.size()>=2) {
        int tmp1=pq.top();
        pq.pop();
        int tmp2=pq.top();
        pq.pop();
        int sum=tmp1+tmp2;
        pq.push(sum);
        //cout<<sum<<'\n';
        ans+=sum;
    }
    cout<<ans<<'\n';
}