#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int dis[1000][1000];
queue<pair<int, int>> q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d_x, d_y;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                d_x = i;
                d_y = j;
            }
            else if (!arr[i][j])
            {
                continue;
            }
            dis[i][j] = -1;
        }
    }
    q.push({d_x, d_y});
    dis[d_x][d_y] = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dis[nx][ny] == -1)
            {
                q.push({nx, ny});
                dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
}