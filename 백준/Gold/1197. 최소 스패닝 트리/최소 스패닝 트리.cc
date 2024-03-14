#include <bits/stdc++.h>
using namespace std;
bool chk[10001];
vector<pair<int, int>> adj[10001];
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    int a, b, c;
    int cnt = 0;
    int ans = 0;
    while (e--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    chk[1] = true;
    for (pair<int,int> nxt : adj[1])
    {
        pq.push({nxt.X, 1, nxt.Y});
    }
    while (cnt < v - 1)
    {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b])
            continue; // 빠트리지 말자
        ans += cost;
        chk[b] = true;
        cnt++;
        for (auto nxt : adj[b])
        {
            if (!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans;
}