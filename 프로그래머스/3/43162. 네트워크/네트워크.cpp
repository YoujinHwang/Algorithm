#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int vis[200]={0};
    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        vis[i]=1;
        cout<<i<<' ';
        answer++;
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(vis[j]==1) continue;
            // cout<<j<<' ';
            if(computers[i][j]==1) {
                queue<int> q;
                q.push(j);
                vis[j]=1;
                
                while(!q.empty()) {
                    int cur=q.front();
                    q.pop();
                    for(int x=0;x<n;x++) {
                        if(vis[x]==1) continue;
                        if(computers[cur][x]==1) {
                            q.push(x);
                            // cout<<x<<' ';
                            vis[x]=1;
                           
                        }
                    }
                }
                
            }
            
            cout<<'\n';
        }
        
    }
    return answer;
}
    