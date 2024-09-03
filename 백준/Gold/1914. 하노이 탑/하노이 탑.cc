#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void func(int a,int b,int n) {
    if(n==1) {
        cout<<a<<' '<<b<<'\n';
        return;
    }
    func(a,6-a-b,n-1);
    cout<<a<<' '<<b<<'\n';
    func(6-a-b,b,n-1);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    string s=to_string(pow(2,k));
    int idx=s.find('.');
    s=s.substr(0,idx);
    s[s.size()-1]-=1;
    cout<<s<<'\n';
    if(k<=20) 
        func(1,3,k);
    
}