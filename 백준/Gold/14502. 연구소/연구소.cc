#include <iostream>
#include <queue>
using namespace std;
int arr[8][8];
int tmp[8][8];
bool vis[64];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
#define X first
#define Y second
vector<pair<int,int>> virus;
vector<pair<int,int>> space;
vector<int> vv;
int Max = 0;
int n, m;

void copy(int tmp[8][8],int arr[8][8]) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j]=arr[i][j];
        }
    }
}
void bfs() {
    queue<pair<int,int>> q;
    for(auto s:virus) {
        q.push(s);
    }
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(!tmp[nx][ny]) {
                tmp[nx][ny]=2;
                q.push({nx,ny});
            }
        }
    }
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(tmp[i][j]==0) cnt++;
        }
    }
    Max=max(Max,cnt);
}

void func(int k,int idx)
{
    if (k == 3)
    {
        copy(tmp,arr);
        //int cnt=0;
        // for(int i=0;i<space.size();i++) {
        //     if(vis[i]) {
        //         int nx=space[i].X;
        //         int ny=space[i].Y;
        //         tmp[nx][ny]=1;
        //         cnt++;
        //     }
        //     if(cnt==3) break;
        // }
        for(auto a:vv) {
            int nx=space[a].X;
            int ny=space[a].Y;
            tmp[nx][ny]=1;
        }
        bfs();
        return;
    }
    
    for (int i = idx+1; i < space.size(); i++)
    {
        // if(!vis[i]) {
        //     //vis[i]=true;
        //     func(k+1,i);
        //     //vis[i]=false;
        // } 
        vv.push_back(i);
        func(k+1,i);
        vv.pop_back();
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]==2) virus.push_back({i,j});
            else if(arr[i][j]==0) space.push_back({i,j}); 
        }
    }
    
    func(0,-1);
    cout << Max;
}