#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define Y first
#define X second
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N,M;
int arr[10][10];
int vis[10][10]; //섬 종류 기록
int cnt = 0;
int parents[7];

struct Bridge {
    int u, v, w;
};

vector<Bridge> bridge;

int Find(int i) {
    if(parents[i]==i) return i;
    return parents[i]=Find(parents[i]);
}

void Union(int a, int b) {
    int newA=Find(a);
    int newB=Find(b);
    if(newA==newB) return;
    parents[newB]=newA;
}

void bfs(int y, int x,int c) { //섬 종류 기록 
    queue<pair<int, int>> q;
    q.push({ y,x });
    vis[y][x] = c;
    int area = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (vis[ny][nx] !=0||arr[ny][nx]==0) continue;
            q.push({ ny,nx });
            vis[ny][nx] = c;
            //cout << c << ' ';
        }
    }

    //cout << '\n';
}

void findBridges() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (vis[y][x] == 0) continue;
            int currentIsland = vis[y][x];

        for (int i = 0; i < 4; i++) {
            int ny = y;
            int nx = x;
            int dist = 0;
            while (true) {
                ny += dy[i];
                nx += dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
                if (vis[ny][nx] == currentIsland) break; //같은 섬이면 중단
                if (vis[ny][nx] > 0) {
                    if (dist > 1) {
                        bridge.push_back({ currentIsland, vis[ny][nx],dist });
                    }
                    break;
                }
                dist++;
            }
        }
    }
}
}

bool cmp(Bridge A, Bridge B) {
    if (A.w < B.w) return true;
    if (A.w > B.w) return false;
    if (A.u < B.u) return true;
    if (A.u > B.u) return false;
    if (A.v < B.v) return true;
    if (A.v > B.v) return false;
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

/*int T;
cin >> T;*/
//for (int i = 1; i <= T; i++) {
    cin >> N>>M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> arr[y][x];
        }
    }
    memset(vis,0,sizeof(vis)); //vis 초기화
    cnt=0; //섬 개수 초기화 
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (arr[y][x] == 1&&vis[y][x]==0) {
                cnt++;
                bfs(y,x,cnt);
            }
        }
    }
    for(int ind=1;ind<=cnt;ind++) { //parents 초기화
        parents[ind]=ind;
    }
//}
/*cout << "\n";
for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
        cout<< vis[y][x]<<' ';
    }
    cout << "\n";
}*/
    findBridges();
    sort(bridge.begin(), bridge.end(), cmp);
    int cnt_bridge=0;
    int ans=0;
    while(!bridge.empty()) {
        Bridge cur=bridge[0];
        bridge.erase(bridge.begin());
        int newA=Find(cur.u);
        int newB=Find(cur.v);
        if(newA==newB) continue;
        else {
            cnt_bridge++;
            Union(cur.u,cur.v);
            ans+=cur.w;
        }
        
        if(cnt_bridge==cnt-1) {
            break;
        }
    }
    int is=Find(1);
    for(int ind=2;ind<=cnt;ind++) {
        if(Find(ind)!=is) {
            cout<<-1<<'\n';
            return 0;
        }
        // cout<<parents[ind]<<' ';
    }
    cout<<ans<<'\n';
}

