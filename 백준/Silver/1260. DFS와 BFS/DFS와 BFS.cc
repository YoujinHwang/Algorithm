#include <bits/stdc++.h>
using namespace std;
queue<int> q;
bool bvis[1001];
bool dvis[1001];
set<int> ve[1001];

void dfs(int a) {
    cout<<a<<' ';
    dvis[a]=true;
    for(int s:ve[a]) {
        if(!dvis[s])
            dfs(s);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, st;
    cin >> n >> m >> st;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        ve[u].insert(v);
        ve[v].insert(u);
    }
    dfs(st);
    cout<<'\n';

    q.push(st);
    bvis[st] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur<<' ';
        for (auto a : ve[cur])
        {
            if (!bvis[a])
            {
                q.push(a);
                bvis[a] = true;
            }
        }
    }
}