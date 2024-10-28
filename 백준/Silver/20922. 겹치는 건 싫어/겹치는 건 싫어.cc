#include<iostream>
#include<cstring>
using namespace std;

int v[100001];
int lst[200000];
int n, k, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> lst[i];

    int l = 0, r = 1;
    v[lst[l]]++;
    int cnt = 1;
    ans = cnt;
    while (r < n) {
        v[lst[r]]++;
        cnt++;
        if (v[lst[r]] > k) {
            while (l < r) {
                v[lst[l]]--;
                cnt--;
                l++;
                if (v[lst[r]] <= k) break;

            }
        }
        ans = max(ans, cnt);
        r++;
    }
    cout << ans;
}