#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
// #include<algorithm>
//브루트포스인 걸 알아채기 힘듦

using namespace std;
bool impos[10];
vector<int> v;

bool isPos(int n)
{
    string num = to_string(n);
    for (int i = 0; i < num.size(); i++)
    {
        if (impos[num[i] - '0'])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x;
        cin >> x;
        impos[x] = true;
    }
    int ans = abs(n - 100);
    for (int i = 0; i <1000000;i++) {
        if(isPos(i)) {
            int sum=abs(i-n)+to_string(i).size();
            ans=min(ans,sum);
        }
    }
    cout<<ans;
}