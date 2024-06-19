#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int m=1000-n;
    int cnt=0;
    while(m>=500) {
        m-=500;
        cnt++;
    }
    while(m>=100) {
        m-=100;
        cnt++;
    }
    while(m>=50) {
        m-=50;
        cnt++;
    }
    while(m>=10) {
        m-=10;
        cnt++;
    }
    while(m>=5) {
        m-=5;
        cnt++;
    }
    while(m>=1){
        m-=1;
        cnt++;
    }
    cout<<cnt;
}