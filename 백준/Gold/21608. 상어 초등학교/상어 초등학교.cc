#include <iostream>
#include <vector>
using namespace std;
vector<int> v[401];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[21][21];
int Empty[21][21];
int like[21][21];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    for(int i=0;i<N*N;i++) {
        int st;
        cin>>st;
        for(int j=0;j<4;j++) {
            int x;
            cin>>x;
            v[st].push_back(x);
        }
        int Max=-1;
        int M_empty=-1;
        int Max_y=1;
        int Max_x=1;
        
        for(int y=1;y<=N;y++) {
            for(int x=1;x<=N;x++) {
                if(arr[y][x]!=0) continue;
                int cnt=0;
                int empty_cnt=0;
                for(int ind=0;ind<4;ind++) {
                    
                    bool isFriend=false;
                    int ny=y+dy[ind];
                    int nx=x+dx[ind];
                    if(nx<1||nx>N||ny<1||ny>N) continue;
                    for(int f=0;f<4;f++) {
                        if(v[st][f]==arr[ny][nx]) {
                            isFriend=true;
                            break;
                        }
                    }
                    if(arr[ny][nx]==0) empty_cnt++;
                    if(isFriend) cnt++;
                }
                Empty[y][x]=empty_cnt;
                if(Max<cnt) {
                    Max=cnt;
                    Max_y=y;
                    Max_x=x;
                    M_empty=empty_cnt;
                }
                else if(Max==cnt) {
                    if(M_empty<empty_cnt) {
                        Max=cnt;
                        Max_y=y;
                        Max_x=x;
                        M_empty=empty_cnt;
                    }
                }
            }
        }
        arr[Max_y][Max_x]=st;
        
    }
    long long tot=0;

    // for(int i=1;i<=N;i++) {
    //     for(int j=1;j<=N;j++) {
    //         cout<<arr[i][j]<<' ';
    //     }
    //     cout<<"\n";
    // }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            int cnt=0;
            for(int ind=0;ind<4;ind++) {
                bool isFriend=false; //위치 중요! 80 줄에 있었음 
                int ny=i+dy[ind];
                int nx=j+dx[ind];
                if(nx<1||nx>N||ny<1||ny>N) continue;
                for(int f=0;f<4;f++) {
                    if(v[arr[i][j]][f]==arr[ny][nx]) {
                        isFriend=true;
                        break;
                    }
                }
                if(isFriend) cnt++;
            }
            if(cnt==2) cnt=10;
            else if(cnt==3) cnt=100;
            else if(cnt==4) cnt=1000;
            tot+=cnt;
        }
    }
    cout<<tot;
}