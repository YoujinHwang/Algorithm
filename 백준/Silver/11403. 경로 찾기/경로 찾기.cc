#include <iostream>

using namespace std;
int arr[101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>arr[i][j];
        }
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(arr[i][j]==1)continue;
                if(arr[i][k]&&arr[k][j])arr[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
}