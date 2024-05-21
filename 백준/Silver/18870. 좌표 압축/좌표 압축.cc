#include <bits/stdc++.h>
using namespace std;
int arr1[1000000];
int arr2[1000000];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr1[i];
        arr2[i]=arr1[i];
    }
    sort(arr2,arr2+n);
    vector<int> vv;
    vv.push_back(arr2[0]);
    for(int i=1;i<n;i++) {
        if(arr2[i]!=arr2[i-1]) {
            vv.push_back(arr2[i]);
        }
    }
    // for(auto s:vv) cout<<s<<' ';
    // cout<<'\n';

    for(int i=0;i<n;i++) {
        long long st=0;
        long long en=vv.size();
        int ans;
        while(st<en) {
            long long mid=(st+en)/2;
            if(vv[mid]>=arr1[i]) {
                en=mid;
            }
            else if(vv[mid]<arr1[i]) {
                st=mid+1;
            }
            ans=en;
        }
        cout<<ans<<' ';
    }
    

}