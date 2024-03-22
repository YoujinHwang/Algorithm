#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int r,c;
int cnt;
int sticker[11][11];
int note[41][41];
bool pastable(int x,int y) {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(sticker[i][j]&&note[x+i][y+j])
                return false;
        }
    }
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(sticker[i][j]==1) {
                note[x+i][y+j]=1;
                cnt++;
            }
        }
    }
    return true;
}

// 90도 회전: A->B; B[x][y]=A[r-1-y][x]
void rotate() {
    int tmp[12][12];
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            tmp[i][j]=sticker[i][j];
        }
    }
    for(int i=0;i<c;i++) {
        for(int j=0;j<r;j++) {
            sticker[i][j]=tmp[r-1-j][i];
        }
    }
    swap(r,c);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    while(k--) {
        cin>>r>>c;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>sticker[i][j];
            }
        }
        for(int rot=0;rot<4;rot++) {
            bool ispaste=false;
            for(int x=0;x<=n-r;x++) {
                if(ispaste) break;
                for(int y=0;y<=m-c;y++) {
                    if(pastable(x,y)) {
                        ispaste=true;
                        break;
                    }
                    
                }
            }
            if(ispaste) break;
            rotate();
        }
    }
   
    cout<<cnt;
    
}