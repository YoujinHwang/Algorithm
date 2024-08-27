#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int N,M;
string arr[9];
int ans=-1;
void choose() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
           string str;
           str=arr[i][j];
           int n=stoi(str);
           if(n==0||n==1||n==4||n==9) {
                ans=max(ans,n);
           }
            for(int dy=-i;i+dy<N;dy++) {
                for(int dx=-j;j+dx<M;dx++) {
                    if(!dx&&!dy) continue;
                    string s;
                    for(int ddy=0, ddx=0;ddy+i<N&&ddy+i>=0&&ddx+j<M&&ddx+j>=0;ddy+=dy,ddx+=dx) {
                        s+=arr[i+ddy][j+ddx];
                        int num=stoi(s);
                        int sq=sqrt(num);
                        if(sq*sq==num&&ans<num) ans=num;
                    }
                   
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    choose();
    cout<<ans;
}