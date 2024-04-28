#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[8];
vector<int> arr2;
int ans[8];
int vis[8];
int ss;
void func(int cnt) {
    if(cnt==m) {
        for(int i=0;i<m;i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<ss;i++) {
        if(vis[i]) {
            ans[cnt]=arr2[i];
            vis[i]--;
            func(cnt+1);
            vis[i]++;
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
    arr2.push_back(arr[0]);
    vis[0]++;
    for(int i=1;i<n;i++) {
        if(arr[i-1]==arr[i]) {
            vis[arr2.size()-1]++;
        }
        else {
            arr2.push_back(arr[i]);
            vis[arr2.size()-1]++;
        }
    }
    ss=arr2.size();
    
    func(0);
    
}