#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int N;
int arr[20][20];
vector<pair<int,int>> v; //자신보다 작은 물고기 위치
pair<int,int> pos; //아기상어 위치
#define Y first
#define X second
int vis[20][20];
int Size=2;
struct Fish {
    int dis;
    pair<int,int> pl;
    bool operator<(const Fish& right)const {
        if(dis>right.dis) return true;
        if(dis<right.dis) return false;
        if(pl.Y>right.pl.Y) return true;
        if(pl.Y<right.pl.Y) return false;
        return pl.X>right.pl.X;

    }
};
Fish nxt; //다음 위치
int cnt=0; //먹이 수
bool bfs() { //다음 먹이 구하기 
    priority_queue<Fish> pq; //먹을 수 있는 물고기 거리순
    
    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<N;j++) vis[i][j]=0;
    // }
    //int Min=INT_MAX;
    
    for(int i=0;i<N;i++)
        fill(vis[i],vis[i]+N,0);
    int chk=0; //거리 확인한 물고기 수
    queue<pair<int,int>> q;
    q.push(pos);
    vis[pos.Y][pos.X]=1;
    //cout<<"pos: "<<pos.Y<<' '<<pos.X<<'\n';
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int ny=cur.Y+dy[i];
            int nx=cur.X+dx[i];
            if(ny<0||ny>=N||nx<0||nx>=N) continue;
            if(vis[ny][nx]) continue;
            if(arr[ny][nx]>Size) {
                //chk++;
                continue;
            } 
            vis[ny][nx]=vis[cur.Y][cur.X]+1; 
            if(arr[ny][nx]<Size&&arr[ny][nx]>0) {
                pq.push({vis[ny][nx]-1,{ny,nx}});
                //cout<<vis[ny][nx]-1<<' '<<ny<<' '<<nx<<'\n';
                //if(Min>vis[ny][nx])
                chk++;
            }
            if(chk==cnt) {
                nxt=pq.top();
                return true;
            } 
            q.push({ny,nx});
        }
    }
    if(pq.size()==0) return false;
    nxt=pq.top();
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
  
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>arr[i][j];
            if(arr[i][j]<=6&&arr[i][j]>0) {
                //v.push_back({i,j});
                cnt++; //총 먹이 수
            }
            else if(arr[i][j]==9) {
                pos={i,j};
                arr[i][j]=0;
            }
        }
    }
    int left=cnt; //남은 물고기
    int time=0; 
    int tmp=0; //먹은 물고기 수
    while(left>0) {
        if(bfs()) {  //다음 먹이 위치
            time+=nxt.dis; //현재 시간
            pos=nxt.pl; //현재 위치
            //cout<<"현재위치: \n";
            //cout<<pos.Y<<' '<<pos.X<<'\n';
            tmp++;
            arr[pos.Y][pos.X]=0;
            left--;
            cnt--;
            if(tmp==Size) {
                Size+=1;
                tmp=0;
            }
            
        }
        else {
            cout<<time;
            return 0;
        }


    }
    cout<<time;
    return 0;
}