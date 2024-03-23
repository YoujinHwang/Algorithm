#include <bits/stdc++.h>
using namespace std;
vector<int> ss;
bool cmp(int x,int y) {
    return x>y;
}
int main() {
     ios::sync_with_stdio(0);
    cin.tie(0);
    long double mean=0;
    int n,score;
    cin>>n;
    for(int i=0;i<n;i++) { //while(n--) 로 쓰면 나중에 n 사용 불가!
        cin>>score;
        ss.push_back(score);
    }
    sort(ss.begin(),ss.end(),cmp);
    int max=ss[0];
    for(auto s:ss) {
        mean+=(long double)s/max*100;
    }
    mean/=n;
    cout<<setprecision(20)<<mean;
}