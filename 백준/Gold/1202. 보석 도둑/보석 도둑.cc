#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<int, int> jw[300000];
multiset<int> bag;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int m, v;
    int c;
    map<int, int> j;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> jw[i].Y >> jw[i].X;
    }
    sort(jw, jw + n);
    while (k--)
    {
        cin >> c;
        bag.insert(c);
    }
    long long cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!bag.empty())
        {
            auto it = bag.lower_bound(jw[i].Y);
            
            if (it != bag.end())
            {
                bag.erase(it);
                cnt += jw[i].X;
            }
        }
        else
            break;
    }
    cout << cnt << '\n';
}