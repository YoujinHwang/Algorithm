#include <queue>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int a[1100][1100];
int M[]={0,1,0,-1,0};
int main() {
    int n,m,ans=0;
    queue<pair<int,int>> q;
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)a[i][0]=1987654321, a[i][m+1]=1987654321;
    for(int i=0;i<=m+1;i++)a[0][i]=1987654321, a[n+1][i]=1987654321;
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) {
        cin>>a[j][i];
        if(a[j][i]==1)q.push({j,i});
    }
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int i=0;i<4;i++) if(a[x+M[i]][y+M[i+1]]==0)
            a[x+M[i]][y+M[i+1]]=a[x][y]+1,q.push({x+M[i],y+M[i+1]});
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j]==0) {
                cout<<-1; 
                return 0;
            }
            ans=max(a[i][j],ans);
        }
    }
    cout<<ans-1<<endl;
    return 0;
}
