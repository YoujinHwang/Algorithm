#include <iostream>
#include <vector>
using namespace std;
int n,m;
long long tot;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        tot=1;
        cin>>n>>m;
        int r=1;
        for(int j=m;j>m-n;j--) {
            tot=tot*j;
            tot=tot/r;
            r++;
        }
        cout<<tot<<'\n';
    }

}