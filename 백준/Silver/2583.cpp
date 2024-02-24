#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
bool arr2[100][100];
#define x first
#define y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> areas;
queue<pair<int, int>> qu;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k;
   
    cin >> m >> n >> k;
    while(k--) {
        pair<int, int> a;
        pair<int, int> b;
        cin >> a.x >> a.y >> b.x >> b.y;
        for (int i = a.x; i <= b.x - 1;i++)
        {
            for (int j = a.y; j <= b.y - 1;j++)
            {
                if(!arr2[i][j]) arr2[i][j]= true;
            }
        }
    }
    int num = 0;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m;j++) {
            if(!arr2[i][j]) {
                num++;
                qu.push({i, j});
                arr2[i][j] = true;
            }

            int area = 0;
            while(!qu.empty()) {
                pair<int, int> cur;
                cur = qu.front();
                area++;
                qu.pop();
                for (int q = 0; q < 4;q++) {
                    int nx = cur.x + dx[q];
                    int ny = cur.y + dy[q];
                    if(nx<0||nx>=n||ny<0||ny>=m)
                        continue;
                    if(!arr2[nx][ny]) {
                        qu.push({nx, ny});
                        arr2[nx][ny] = true;
                    }
                }
            }
            if(area!=0) areas.push_back(area);
        }
    }
    sort(areas.begin(), areas.end());
    cout << num << '\n';
    for(auto a:areas)
        cout << a << ' ';
};