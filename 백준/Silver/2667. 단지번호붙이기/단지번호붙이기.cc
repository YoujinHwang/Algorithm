#include <bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[25][25];
bool vis[25][25];
vector<int> area;
queue<pair<int,int>> q;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        int j=0;
        for(char c:s) {
            arr[i][j++]=c-'0';
        }
    }
    int cnt=0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]==1&&!vis[i][j]) {
                q.push({i,j});
                vis[i][j]=1;
                cnt++;
                int a=0;
                while(!q.empty()) {
                    pair<int,int> cur;
                    cur=q.front();
                    q.pop();
                    arr[cur.X][cur.Y]=cnt;
                    a++;
                    
                    for(int ind=0;ind<4;ind++) {
                        int nx=cur.X+dx[ind];
                        int ny=cur.Y+dy[ind];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(arr[nx][ny]==1&&!vis[nx][ny]) {
                            q.push({nx,ny});
                            vis[nx][ny]=1;
                        } 
                    }
                }
                area.push_back(a);
            }
        }
    }
    sort(area.begin(),area.end());
    cout<<cnt<<'\n';
    for(auto s:area)
        cout<<s<<'\n';
    
}