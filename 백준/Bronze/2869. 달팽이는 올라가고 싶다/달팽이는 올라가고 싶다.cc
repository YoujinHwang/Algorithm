#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,v;
    cin>>a>>b>>v;
    
    int tmp=a-b;
    int cnt=(v-a)/tmp;
    int r=(v-a)%tmp;
    if(r==0) cnt+=1;
    else cnt+=2;
   
    cout<<cnt;
}