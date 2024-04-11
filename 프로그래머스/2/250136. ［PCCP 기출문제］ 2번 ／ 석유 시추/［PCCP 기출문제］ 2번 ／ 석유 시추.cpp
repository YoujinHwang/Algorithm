#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
#define X first
#define Y second
int vis[500][500];

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n=land.size();
    int m=land[0].size();
    int oil_area[250000]={};
    int num=0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int cnt=0;
            if(!vis[i][j]&&land[i][j]) { //land[i][j] 조건 빠트림..
                    q.push({i,j});
                    cnt++;
                    num+=1;
                    cout<<num<<' ';
                    vis[i][j]=num;
                    while(!q.empty()){
                        pair<int,int> cur=q.front();
                        q.pop();
                        for(int idx=0;idx<4;idx++) {
                            int nx=cur.X+dx[idx];
                            int ny=cur.Y+dy[idx];
                            if(nx<0||ny<0||nx>=n||ny>=m) continue;
                            if(!vis[nx][ny]&&land[nx][ny]) {
                                q.push({nx,ny});
                                vis[nx][ny]=num;
                                cnt++;
                            } 
                        }
                    }
                    oil_area[num]=cnt;
            }
            
        }
    }
    
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             cout<<vis[i][j]<<' ';
//         }
//         cout<<'\n';
//     }
    
//     for(int i=1;i<=num;i++) {
//         cout<<oil_area[i]<<' ';
//     }
    
    
    for(int i=0;i<m;i++) {
        int tmp=0;
        bool vis_oil[250000]={};
        for(int j=0;j<n;j++) {
            int x=vis[j][i];
            if(x&&!vis_oil[x]) {
                tmp+=oil_area[x];
                vis_oil[x]=true;
            }
        }
        answer=max(answer,tmp);
    }
    return answer;
}