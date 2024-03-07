#include <bits/stdc++.h>
using namespace std;
#include <math.h>


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==0&&y==0&&z==0) return 0;
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        sort(v.begin(),v.end());
        if(pow(v[0],2)+pow(v[1],2)==pow(v[2],2))
            cout<<"right"<<'\n';
        else cout<<"wrong"<<'\n';

    }
}