#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define Y first
#define X second
int n,m;
int A[55][55];
int ord_dy[8]={0,-1,-1,-1,0,1,1,1};
int ord_dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[4]={-1,-1,1,1};
int dx[4]={-1,1,1,-1};
set<pair<int,int>> clouds;
set<pair<int,int>> rain;

void func(int d,int s) {
   
    // for(auto it:clouds) {
    //     cout<<it.Y<<' '<<it.X<<'\n';
    // }
    for(auto it:clouds) {
        int ny=(it.Y+s*ord_dy[d]+n*s-1)%n+1; //여기 s가 커서 음수가 될 수 있으므로 그냥 n이 아닌 n*s를 더해주어야함!
        int nx=(it.X+s*ord_dx[d]+n*s-1)%n+1;
        // if(ny>n) {
        //     ny=ny%n;
        //     if(ny==0) ny=n; //n으로 나누어 떨어지는 경우는 n행이므로
        // }
        // if(nx>n) {
        //     nx=nx%n;
        //     if(nx==0) nx=n;
        // }
        rain.insert({ny,nx});
        
    }

    // for(auto it:rain) {
    //     cout<<it.Y<<' '<<it.X<<'\n';
    // }

    for(auto it:rain) {
        A[it.Y][it.X]++;
    }

    // cout<<'\n';
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout<<A[i][j]<<' ';
    //     }
    //     cout<<"\n";
    // }

    for(auto it:rain) {
        int cnt=0;
        for(int ind=0;ind<4;ind++) {
            int nny=it.Y+dy[ind];
            int nnx=it.X+dx[ind];
            if(nny<1||nny>n||nnx<1||nnx>n) continue;
            if(A[nny][nnx]>0) cnt++;
        }
        A[it.Y][it.X]+=cnt;
    }
    
    // for(auto it:rain) {
    //     cout<<it.Y<<' '<<it.X<<'\n';
    // }

    set<pair<int,int>> tmp;
    for(int y=1;y<=n;y++) {
        for(int x=1;x<=n;x++) {
            bool isPass=false;
            for(auto it:rain) {
                if(y==it.Y&&x==it.X){
                    isPass=true;
                    break; //스댕 break가 괄호 안에 없었음,,,
                }  
            }
            if(!isPass) {
                if(A[y][x]>=2) {
                    tmp.insert({y,x});
                    A[y][x]-=2;
                }
            }
        }
    }
    rain.clear();
   
    clouds=tmp;
    
    // cout<<'\n';
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout<<A[i][j]<<' ';
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>A[i][j];
        }
    }
   
    clouds.insert({n,1});
    clouds.insert({n,2});
    clouds.insert({n-1,1});
    clouds.insert({n-1,2});
    
    for(int i=0;i<m;i++) {
        int s,d;
        cin>>d>>s;
        // cout<<"command "<<i+1<<d<<' '<<s<<"\n";
        d--;
        func(d,s);
    }
    
    int tot=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            tot+=A[i][j];
        }
    }
    cout<<tot;
}