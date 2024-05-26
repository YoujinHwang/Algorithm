#include <iostream>
using namespace std;
int n;

void func(int cnt) {
    if(cnt==n-1) {
        for(int i=0;i<2*(n-1)+1;i++) {
            cout<<'*';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<n-cnt;i++) {
        cout<<' ';
    }
    for(int i=0;i<2*cnt+1;i++) {
        cout<<'*';
    }
    cout<<'\n';
    func(cnt+1);
    for(int i=1;i<n-cnt;i++) {
        cout<<' ';
    }
    for(int i=0;i<2*cnt+1;i++) {
        cout<<'*';
    }
    cout<<'\n';

} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    func(0);
}