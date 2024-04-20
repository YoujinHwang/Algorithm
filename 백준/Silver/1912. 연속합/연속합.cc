#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int dp[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        arr.push_back(x);
    }
    dp[0]=arr[0];
    for(int i=1;i<n;i++) {
        dp[i]=max(arr[i],dp[i-1]+arr[i]);   
    }
    sort(dp,dp+n);
    cout<<dp[n-1];
}