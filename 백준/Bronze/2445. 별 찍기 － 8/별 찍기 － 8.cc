#include <iostream>
using namespace std;
int n;
void func(int cnt) {
    if(cnt==n) {
        for(int i=0;i<2*n;i++) {
            cout<<'*';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<cnt;i++) 
        cout<<'*';
    for(int i=cnt;i<2*n-cnt;i++)
        cout<<' ';
    for(int i=0;i<cnt;i++)
        cout<<'*';
    cout<<'\n';
    func(cnt+1);
    for(int i=0;i<cnt;i++)
        cout<<'*';
    for(int i=cnt;i<2*n-cnt;i++)
        cout<<' ';
    for(int i=0;i<cnt;i++) 
        cout<<'*';
    cout<<'\n';
}

int main() {
    cin>>n;
    func(1);
}