#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[500000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    vector<int> v;
    
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++) {
        int st=0;
        int end=n-1;
        while(st<=end) { 
            int mid=(st+end)/2;
            if(v[mid]<arr[i]) {
                st=mid+1;
            }
            else if(v[mid]>arr[i]) {
                end=mid-1;
            }
            else {
                cout<<1<<' ';
                break;
            }
        }
        if(st>end) {
            cout<<0<<' ';
        }
    }

}