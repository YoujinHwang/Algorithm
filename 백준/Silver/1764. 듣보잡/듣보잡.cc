#include <bits/stdc++.h>
using namespace std;

set<string> s1;
set<string> s2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    while (n--)
    {
        string name;
        cin >> name;
        s1.insert(name);
    }
    while (m--)
    {
        string unseen;
        cin >> unseen;
        if (s1.find(unseen) != s1.end())
        {
            cnt++;
            s2.insert(unseen);
        }
    }
    cout << cnt << '\n';
    for (auto a : s2)
        cout << a << '\n';
}