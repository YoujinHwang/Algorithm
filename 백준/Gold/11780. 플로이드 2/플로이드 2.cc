#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dis[101][101];
int path[101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++)
        fill(dis[i], dis[i] + 1 + n, INF);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        path[a][b] = b;
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    path[i][j] = path[i][k]; //주의
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << path[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (dis[i][j] == 0 || dis[i][j] == INF) //거리가 0이거나 무한대
                cout << 0 << '\n';
            else
            {   
                vector<int> vv;
                int st=i;
                while(st!=j) {
                    vv.push_back(st);
                    st=path[st][j];
                }
                vv.push_back(j);
                cout<<vv.size()<<' ';
                for(int x:vv) cout<<x<<' ';
                cout << '\n';
            }
        }
    }
}