#include <bits/stdc++.h>
using namespace std;
int n;
string arr[10];
char cur[10][10];
int dy[8]={1,-1,0,0,-1,-1,1,1};
int dx[8]={0,0,1,-1,-1,1,1,-1};
char ans[10][10]={'.'};
vector<pair<int,int>> v;
#define X first
#define Y second

// void gameOver() {
//     for(int i=0;i<n;i++) {
//         cout<<arr[i]<<'\n';
//     }
//     return;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool gameOver=false;
    cin>>n;
    // bool gameOver=false;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j]=='*') {
                v.push_back({i,j});
            }
        }
        
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>cur[i][j];
            if(cur[i][j]=='x'&&arr[i][j]=='*') { //지뢰 밟는 경우
                gameOver=true;
                
            }
            
        }
        
    }
    // if(gameOver) {
    //     for(auto s : v) {
    //         ans[s.first][s.second]='*';
    //     }
    // }

    if(gameOver) {
        for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]=='*') {
                ans[i][j]='*';
            }
        }
    }
    }
    

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout<<ans[i][j];
    //     }
    //     cout<<'\n';
    // }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(gameOver&&arr[i][j]=='*') continue;
            if(cur[i][j]=='x'&&arr[i][j]!='*') {
                int cnt=0;
                for(int k=0;k<8;k++) {
                    // cout<<1;
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(arr[ny][nx]=='*') {
                        cnt++;
                    }
                }
                ans[i][j]='0'+cnt;
                
            }
            else {
                
                ans[i][j]='.';
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}
