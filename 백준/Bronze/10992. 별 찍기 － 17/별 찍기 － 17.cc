#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++) 
        cout<<' ';
    cout<<'*';
    cout<<'\n';
    if(n==1) return 0;
    for(int i=2;i<n;i++) {
        for(int j=0;j<n-i;j++)
            cout<<' ';
        cout<<'*';
        for(int j=0;j<2*(i-1)-1;j++)
            cout<<' ';
        cout<<'*';
        cout<<'\n';
    }
    for(int i=0;i<2*n-1;i++)
        cout<<'*';
}