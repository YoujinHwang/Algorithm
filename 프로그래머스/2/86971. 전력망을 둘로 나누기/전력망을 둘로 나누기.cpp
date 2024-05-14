#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
vector<int> info[101];
bool vis[101];
queue<int> q;
int Min=INT_MAX;

int bfs(int a) {
    int cnt=1;
    q.push(a);
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for(int i=0;i<info[cur].size();i++) {
            if(!vis[info[cur][i]]) {
                q.push(info[cur][i]);
                vis[info[cur][i]]=true;
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    for(int i=0;i<n-1;i++) {
        info[wires[i][0]].push_back(wires[i][1]);
        info[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i=0;i<n-1;i++) {
        fill(vis,vis+101,false);
        vis[wires[i][0]]=true;
        vis[wires[i][1]]=true;
        int cnt=bfs(wires[i][0]);
        int dif=abs(cnt-(n-cnt));
        Min=min(dif,Min);
    }
    answer=Min;
    return answer;
}