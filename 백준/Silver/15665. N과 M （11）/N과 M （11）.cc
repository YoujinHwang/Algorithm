#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int arr[7];
vector<int> arr2;
int ans[7];

void func(int cnt) {
    if(cnt==m) {
        for(int i=0;i<m;i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<arr2.size();i++) {
        ans[cnt]=arr2[i];
        func(cnt+1);
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
    for(int i=1;i<n;i++) {
        if(arr[i]==arr[i-1]) continue;
        arr2.push_back(arr[i]);
    }
    func(0);
}