#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<int> arr[10001];
bool chk[10001];
int depth[10001];

int dfs(int st) {
    int cnt=1;
    chk[st]=true;
    for(auto s:arr[st]) {
        if(!chk[s]) {
            cnt+=dfs(s);
        }
    }
    return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--) {
        int u,v;
        cin>>u>>v;
        arr[v].push_back(u);
    }
    vector<int> ans;
  
    for(int i=1;i<=n;i++) {
        depth[i]=dfs(i);
        for(int j=1;j<=n;j++) 
            chk[j]=false;
    }
    int Max=*max_element(depth+1,depth+n+1);
    for(int i=1;i<=n;i++) {
        if(depth[i]==Max) {
            ans.push_back(i);
        }
    }
    //for(int i=1;i<=n;i++) cout<<depth[i]<<' ';
    //cout<<'\n';
    for(auto s:ans)
        cout<<s<<' ';
}