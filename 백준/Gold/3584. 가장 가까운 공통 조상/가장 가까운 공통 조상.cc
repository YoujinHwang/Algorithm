#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
vector<int> v[10001];
int par[10001][15]; //1<<14 = 16,384
int d[10001];

void dfs(int i,int dep) {
    d[i]=dep;
    for(int s:v[i]) {
        dfs(s,dep+1);
    }
}

void setPar() {
    for(int i=1;i<15;i++) {
        for(int j=1;j<=N;j++) {
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
}

int lca(int a,int b) {
    if(d[a]>d[b]) {
        swap(a,b);
    }
    for(int i=14;i>=0;i--) {
        if(d[b]-d[a]>=(1<<i)) { 
            b=par[b][i];
        }
    }
    if(a==b) return a; //아 이거 빠트림..
    for(int i=14;i>=0;i--) {
        if(par[a][i]!=par[b][i]) {
            a=par[a][i];
            b=par[b][i];
        }
    }
    return par[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int ind=0;ind<T;ind++) {
        cin>>N;
        for(int i=1;i<=N;i++) {
            v[i].clear();
        }
        memset(par,0,sizeof(par));
        for(int i=0;i<N-1;i++) {
            int A,B;
            cin>>A>>B;
            v[A].push_back(B);
            par[B][0]=A;
        }
        
        for(int i=1;i<=N;i++) {
            if(par[i][0]==0) {
                // cout<<"root : "<<i<<'\n';
                dfs(i,0);
                break;
            } 
        }
        
        setPar();
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }
}