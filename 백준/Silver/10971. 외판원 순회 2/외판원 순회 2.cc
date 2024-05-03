#include <iostream>
#include <vector>
#include<climits>

using namespace std;
int n;
int arr[10][10];
bool vis[10];
int Min=INT_MAX;

void func(int ind,int cnt,int tot) {
    if(cnt==n-1) { //cnt==n이라고 해서 계속 Min 값이 INT_MAX로 나옴...
        if (arr[ind][0] > 0) {
            tot+=arr[ind][0];
            Min=min(Min,tot);
        }
        return;
    }
    for(int i=0;i<n;i++) {
        //if(i==ind) continue;
        if(!vis[i]&&arr[ind][i]>0) {
            vis[i]=true;
            func(i,cnt+1,tot+arr[ind][i]); //tot를 매개로 넘겨줬을 때 업데이트를 하기 용이 & tot를 원래 값으로 되돌려 놓는 과정 용이  
            vis[i]=false;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    vis[0]=true;
    func(0,0,0);
    cout<<Min;
}