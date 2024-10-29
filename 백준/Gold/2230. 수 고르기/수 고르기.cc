#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int arr[100000];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l=0;
    int r=0;
    int ans=2000000000;
    while(r<n) {
        int dif=arr[r]-arr[l];
        if(dif>=m) {
            ans=min(ans,dif);
            l++;
            
        }
        else {
            r++;
        }
    }

    cout<<ans;
}