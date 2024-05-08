#include <iostream>
#include <vector>
using namespace std;

char map[401][401];

void func(int x,int y,int n) {
    if(n==1) {
        map[x][y]='*';
        return;
    }
    else {
        int len=4*n-3;
        for(int j=y;j<y+len;j++) {
            map[x][j]='*';
            map[x+len-1][j]='*';
        }

        for(int i=x;i<x+len;i++) {
            map[i][y]='*';
            map[i][y+len-1]='*';
        }
        func(x+2,y+2,n-1);
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=0;i<4*n-3;i++) {
        for(int j=0;j<4*n-3;j++) {
            map[i][j]=' ';
        }
    }
    func(0,0,n);

    for(int i=0;i<4*n-3;i++) {
        for(int j=0;j<4*n-3;j++) {
            cout<<map[i][j];
        }
        cout<<'\n';
    }

}