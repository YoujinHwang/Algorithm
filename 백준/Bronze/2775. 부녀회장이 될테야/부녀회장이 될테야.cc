#include <iostream>
using namespace std;

int dp[15][15];

int main() {
    int t;
    cin>>t;
   
    for(int i=1;i<=14;i++) {
        dp[0][i]=i;
    }
    for(int i=1;i<=14;i++) {
        dp[i][1]=dp[i-1][1];
    }
    for(int i=1;i<=14;i++) {
        for(int j=2;j<=14;j++) {
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }

    for(int i=0;i<t;i++) {
        int k,n;
        cin>>k>>n;
        cout<<dp[k][n]<<'\n';
    }
}