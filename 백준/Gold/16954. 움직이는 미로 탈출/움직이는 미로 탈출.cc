#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second
string arr[8];
int dy[] = { 1,-1,0,0,1,-1,1,-1,0 }; //아래 위 오 왼 우하 좌상 좌하 우상 그대로
int dx[] = { 0,0,1,-1,1,-1,-1,1,0 };
bool isFin;
bool isWin;
int vis[8][8];


bool moveWall(int y,int x,string a[8]) {
    for (int i = 7; i >= 1; i--) {
        
        a[i] = a[i - 1];
    }
    a[0] = "........";
    if (a[y][x] == '#') {
        isFin = true;
        
    }
    return isFin;
}

void movePer(int y,int x, string a[],int cnt) {
   
    if (isWin||cnt==7) {
        //cout << 1;
        isWin = true;
        return;
    }
    string tmp[8];
    
    
   
    for (int i = 0; i < 9; i++) {
        copy(&a[0], &a[0] + 8, &tmp[0]);
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
        if (tmp[ny][nx] == '#') continue;
        
        if (ny == 0 ) {
            isWin = true;
            //cout << 1;
            return;
        }
      
        if (moveWall(ny, nx, tmp)) {
            //cout << 0;
            isFin = false;
            continue;
        }
        movePer(ny, nx,tmp,cnt+1);
        
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    movePer(7,0,arr,0);
    if (!isWin) cout << 0;
    else cout << 1;
   
}