#include <iostream>
#include <vector>
using namespace std;
char arr[21][21];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int r,c;
bool impos[26];
int cc;

void count(int x,int y,int cnt){

    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1||nx>r||ny<1||ny>c) continue;
        int n=arr[nx][ny]-'A';
        if(impos[n]) continue;
        impos[n]=true;
        cnt++;
        count(nx,ny,cnt);
        cnt--;
        impos[n]=false;
    }
    cc=max(cc,cnt);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c;
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cin>>arr[i][j];
        }
    }
    int n=arr[1][1]-'A';
    impos[n]=true;
    count(1,1,1);
    cout<<cc;
}