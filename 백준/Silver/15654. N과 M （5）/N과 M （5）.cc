#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[8];
bool isused[8];
int ans[8];

void func(int k) {
    if(k==m) {
        for(int i=0;i<m;i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++) {
        if(!isused[i]) {
            ans[k]=arr[i];
            isused[i]=1;
            func(k+1);
            isused[i]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    func(0);
}