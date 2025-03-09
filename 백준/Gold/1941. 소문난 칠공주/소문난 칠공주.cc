#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define Y first 
#define X second 

char arr[5][5];
int vis[5][5];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int ans;
vector<pair<int,int>> tmp;


void BFS() {
    int cnt=1;
    queue<pair<int,int>> q;
    // for(int i=0;i<5;i++) {
    //     for(int j=0;j<5;j++) {
    //         if(vis[i][j]==1) {
    //             q.push({i,j});
    //             vis[i][j]=0;
    //             break;
    //         }
    //     }
    // }
    q.push(tmp[0]);
    vis[tmp[0].Y][tmp[0].X]=0;
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nxt_y=cur.Y+dy[i];
            int nxt_x=cur.X+dx[i];
            if(nxt_y<0||nxt_y>=5||nxt_x<0||nxt_x>=5||vis[nxt_y][nxt_x]==0) continue;
            q.push({nxt_y,nxt_x});
            vis[nxt_y][nxt_x]=0;
            cnt++;
        }
    }
    if(cnt==7) ans++;
    
}
int cnt_y=0;
//int cnt_s=0;

bool imp;
void search() {
    int seat[25]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    do{
        tmp.clear();
        cnt_y=0;
        imp=false;
        for(int y=0;y<5;y++) 
            fill(vis[y],vis[y]+5,0);
        //cnt_s=0;
        for(int i=0;i<25;i++) {
            if(seat[i]==0) {
                int r=i/5;
                int c=i%5;
                if(arr[r][c]=='Y') cnt_y++;
                if(cnt_y==4) {
                    imp=true;
                    break;
                }
                vis[r][c]=1;
                tmp.push_back({r,c});
            }
        }
        if(imp) continue;

        BFS();

        
    }while(next_permutation(seat,seat+25));
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin>>arr[i][j];
        }
    }
    search();
    cout<<ans<<'\n';

}