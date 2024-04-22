#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[8];
int n,m;
bool isused[8];
int ans[8];
void fc(int cnt,int k) {
    if(cnt==m) {
        for(int i=0;i<m;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=k;i<n;i++) {
        if(!isused[i]) {
            ans[cnt]=arr[i];
            isused[i]=true;
            fc(cnt+1,i+1);
            isused[i]=false;
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
    fc(0,0);
}