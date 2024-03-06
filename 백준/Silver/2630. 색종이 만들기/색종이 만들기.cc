#include <bits/stdc++.h>
using namespace std;
int arr[128][128];
// bool dif;
bool white;
bool blue;
int b_cnt;
int w_cnt;
bool check(int a, int b, int n)
{
    for (int i = a; i < a+n; i++)
    {
        for (int j = b; j < b+n; j++)
        {
            if (arr[i][j] == 1)
            {
                blue = true;
            }
            else
                white = true;
            if (blue && white)
                break;
        }
    }
    if (!blue || !white)
    {
        if (blue) {
            b_cnt++;
            //cout<<"b_cnt:"<<b_cnt<<' ';
        }
            
        else {
             w_cnt++;
            //cout<<"w_cnt:"<<w_cnt<<' ';
        }
        blue = false;
        white = false;
        return true;
    }
    blue = false;
    white = false;
    return false;
}
void cut(int a, int b, int n)
{
    if (n == 1)
    {
        if (arr[a][b] == 1)
        {
            b_cnt++;
           // cout<<"b_cnt:"<<b_cnt<<' ';
        }
        else {
            w_cnt++;
            //cout<<"w_cnt:"<<w_cnt<<' ';
        }
            
        return;
    }
    if(!check(a, b, n)) {
        cut(a, b, n / 2);
        cut(a + n / 2, b, n / 2);
        cut(a, b + n / 2, n / 2);
        cut(a + n / 2, b + n / 2, n / 2);
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cut(0, 0, n);
    cout<<w_cnt<<'\n'<<b_cnt;
}