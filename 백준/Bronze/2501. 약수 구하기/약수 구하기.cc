#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> ans;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) {
            ans.push_back(i);
            if(i!=n/i) {
                ans.push_back(n/i);
            }
           
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()<k) {
        cout<<0;
        return 0;
    } 
    cout<<ans[k-1];
}