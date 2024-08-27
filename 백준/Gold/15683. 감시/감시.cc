#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
int N,M;
int arr[8][8];
int arr2[8][8];


struct Cctv{
    int num;
    int y,x;
};
vector<Cctv> cctv;
int vis[8];
int Size;
int Min=INT_MAX;


//0 : 위, 1: 오, 2:아래, 3: 왼
int dy[4]={-1,0,1,0};
int dx[]={0,1,0,-1};

void chk(int in, int y,int x) { // in 방향에 따라 벽 만날때까지 #표시
    if(arr2[y][x]==6) {
        return;
    }
    if(arr2[y][x]==0) arr2[y][x]=-1;
    int ny=y+dy[in];
    int nx=x+dx[in];
    if(ny<0||ny>=N||nx<0||nx>=M) return;
    chk(in,ny,nx);
}
void dir(int dd[4],Cctv c) { //해당 방향별로 chk 함수 호출
    for(int i=0;i<4;i++) {
        if(dd[i]) {
            chk(i, c.y,c.x);
        }
    }
}
void seek() { //cctv 번호별로 해당 하는 방향에만 dd 배열에서 1로 할당
    for(int i=0;i<Size;i++) {
        int n=cctv[i].num;
        int dd[4]={0};
        if(n==1) {
            
            dd[vis[i]]=1;
            dir(dd, cctv[i]);
        }
        else if(n==3) {
            dd[vis[i]]=1;
            int nxt=(vis[i]+1)%4;
            dd[nxt]=1;
            dir(dd,cctv[i]);
        }
        
        else if(n==4) {
            memset(dd,1,sizeof(dd));
            dd[vis[i]]=0;
            dir(dd,cctv[i]);
        }
        else if(n==2) {
            dd[vis[i]]=1;
            dd[vis[i]+2]=1;
            dir(dd,cctv[i]);
        }
        else if(n==5) {
            memset(dd,1,sizeof(dd));
            dir(dd,cctv[i]);
        }
    }
}

int count() {
    int cnt=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr2[i][j]==0) cnt++;
        }
    }
    return cnt;
}

void dfs(int cnt) {
    if(cnt==Size) {
   
        seek();
        Min=min(Min,count());
        for(int i=0;i<N;i++) { //초기화 꼭 해줘야함!! 매번 새로운 지도에서 다시 시작해야하므로! 
            for(int j=0;j<M;j++) {
                arr2[i][j]=arr[i][j];
            }
        
        }
        return;
    }
    if(cctv[cnt].num==5) {
        vis[cnt]=1;
        dfs(cnt+1);
    } 
    else if(cctv[cnt].num==2) {
        for(int i=0;i<2;i++) {
            vis[cnt]=i;
            dfs(cnt+1);

        }
    }
    else {
        for(int i=0;i<4;i++) {
            vis[cnt]=i;
            dfs(cnt+1);

        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>arr[i][j];
            if(arr[i][j]>=1&&arr[i][j]<=5) {
                cctv.push_back({arr[i][j],i,j});
            }
            arr2[i][j]=arr[i][j];
        }
    }
    Size=cctv.size();
    dfs(0);
   
    cout<<Min;
}