#include <bits/stdc++.h>
using namespace std;

#define R first
#define C second

int N, M;
int board[51][51];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int answer = INT_MAX;

// idx: 현재 고려 중인 치킨집 인덱스
// selected: 지금까지 고른 치킨집 인덱스 저장
void dfs(int idx, vector<int> &selected)
{
    // selected.size()가 M이 되면 지금까지 고른 치킨집 조합에 대해 거리 계산
    if (selected.size() == M)
    {
        int cityDist = 0;
        for (auto &h : houses)
        {
            int hr = h.R;
            int hc = h.C;
            int distMin = INT_MAX;

            for (int cidx : selected)
            {
                int cr = chickens[cidx].R;
                int cc = chickens[cidx].C;
                int dist = abs(hr - cr) + abs(hc - cc);
                distMin = min(distMin, dist);
            }
            cityDist += distMin;
        }
        answer = min(answer, cityDist);
        return;
    }

    if (idx >= chickens.size())
        return;

    // 1) 현재 idx 치킨집을 고르는 경우
    selected.push_back(idx);
    dfs(idx + 1, selected);
    selected.pop_back();

    // 2) 현재 idx 치킨집을 고르지 않는 경우
    dfs(idx + 1, selected);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            cin >> board[r][c];
            if (board[r][c] == 1)
                houses.push_back({r, c});
            else if (board[r][c] == 2)
                chickens.push_back({r, c});
        }
    }
    vector<int> selected;
    dfs(0, selected);

    cout << answer << '\n';

    return 0;
}