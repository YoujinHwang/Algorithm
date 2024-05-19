#include <iostream>
#include <vector>
using namespace std;

#define Max 100000
int st[2][Max];
int dp[2][Max];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        for(int j=0;j<2;j++) {
            for(int k=0;k<n;k++)
                cin>>st[j][k];
        }
        dp[0][0]=st[0][0];
        dp[1][0]=st[1][0];
        dp[0][1]=st[1][0]+st[0][1];
        dp[1][1]=st[0][0]+st[1][1];

        for(int j=2;j<n;j++) {
            dp[0][j]=max(dp[1][j-1],dp[1][j-2])+st[0][j];
            dp[1][j]=max(dp[0][j-1],dp[0][j-2])+st[1][j];
        }
        cout<<max(dp[0][n-1],dp[1][n-1])<<'\n';
    }
}