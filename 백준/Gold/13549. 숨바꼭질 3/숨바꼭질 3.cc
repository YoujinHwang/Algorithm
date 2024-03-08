#include <bits/stdc++.h>
using namespace std;
int vis[200001];

queue<int> q;
int dx[2] = {1, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    q.push(n);
    vis[n] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        if (cur == k)
        {
            cout << vis[cur] - 1 << '\n';
            return 0;
        }
        q.pop();
        int nx = cur * 2;
        if (nx >= 0 && nx <= 200000&&(!vis[nx]||vis[nx]>vis[cur]))
        {
            q.push(nx);
            vis[nx] =vis[cur];
        }
        for (int i = 0; i < 2; i++)
        {
            nx = cur + dx[i];
            if (nx < 0 || nx > 200000)
                continue;
            if (!vis[nx]||vis[nx]>vis[cur]+1)
            {
                q.push(nx);
                vis[nx] = vis[cur] + 1;
            }
        }
    }
}