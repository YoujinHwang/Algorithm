#include <bits/stdc++.h>
using namespace std;
//#include <set>

int d[500][500];
int arr[500][500];
set<int> os;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
             cin>>arr[i][j];
        }
    }
    int Max=0;
    d[0][0]=arr[0][0];
    for(int i=1;i<n;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0) d[i][j]=d[i-1][j]+arr[i][j];
            else if(j==i) d[i][j]=d[i-1][j-1]+arr[i][j];
            else d[i][j]=max(d[i-1][j-1],d[i-1][j])+arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
        Max=max(Max,d[n-1][i]);
    cout<<Max;
}