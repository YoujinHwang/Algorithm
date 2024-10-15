#include <iostream>
#include <vector>
using namespace std;
#define Y first 
#define X second
int dy[]={-1,-1,0,1,1,1,0,-1};
int dx[]={0,1,1,1,0,-1,-1,-1};
int N,M,K;

struct fireBall {
    //pair<int,int> pos;
    int m,s, d; //질량,속력, 뱡향
};
vector<fireBall> arr[51][51];

//fireBall fb[2501];

pair<int,int> rangeChk(int y, int x) {
    if(y<=0) {
        y=y+N;

    }
    else if(y>N) {
        y=y-N;
    }
    if(x<=0) {
        x=x+N;
    }
    else if(x>N) {
        x=x-N;
        
    }
    return {y,x};
}

void Move() {
    vector<fireBall> newArr[51][51];
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[i][j].size()>1) {
                int weight=0;
                bool Odd=false;
                bool Even=false;
                int speed=0;
                for(auto ball:arr[i][j]) {
                    if(ball.d%2==0) Even=true;
                    else Odd=true;
                    weight+=ball.m;
                    speed+=ball.s;
                }
                weight/=5;
                if(weight==0) {
                    arr[i][j].clear();
                    continue;
                }
                speed/=arr[i][j].size();
                int tmp=speed%N;
                if(Odd&&Even) {
                    for(int ind=1;ind<=7;ind+=2) {
                        int ny=i+dy[ind]*tmp;
                        int nx=j+dx[ind]*tmp;
                        pair<int,int> nxt=rangeChk(ny,nx);
                        newArr[nxt.Y][nxt.X].push_back({weight,speed,ind});
                    }
                }
                else {
                    for(int ind=0;ind<=6;ind+=2) {
                        int ny=i+dy[ind]*tmp;
                        int nx=j+dx[ind]*tmp;
                        pair<int,int> nxt=rangeChk(ny,nx);
                        //cout<<nxt.Y<<' '<<nxt.X<<'\n';
                        newArr[nxt.Y][nxt.X].push_back({weight,speed,ind});
                    }
                }
            }
            else if(arr[i][j].size()==1) {
                fireBall now=arr[i][j][0];
                int speed=now.s%N;
                int ny=i+dy[now.d]*speed;
                int nx=j+dx[now.d]*speed;
                pair<int,int> nxt=rangeChk(ny,nx);
                //cout<<nxt.Y<<' '<<nxt.X<<'\n';
                newArr[nxt.Y][nxt.X].push_back({now.m,now.s,now.d});
            }
        }
    }
    for(int i=1;i<=N;i++) copy(newArr[i],newArr[i]+N+1,arr[i]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i=1;i<=M;i++) {
        int r,c,m,s,d;
        cin>>r>>c>>m>>s>>d;
        //fb[i]={{r,c},m,s,d};
        arr[r][c].push_back({m,s,d});
    }
    while(K--) {
        Move();
    }
    
    int ans=0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[i][j].size()>1) {
                int w=0;
                for(auto s:arr[i][j]) {
                    w+=s.m;
                }
                ans+=(w/5*4);
            }
            else if(arr[i][j].size()==1)
                ans+=arr[i][j][0].m;
        }
    }
    cout<<ans;
}