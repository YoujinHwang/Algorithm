#include <iostream>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            cout<<' ';
        }
        for(int j=0;j<2*n-1-(i*2);j++) {
            cout<<'*';
        }
        cout<<'\n';
    }
    
}