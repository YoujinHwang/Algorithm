#include <bits/stdc++.h>
using namespace std;
queue<int> q;
char lc[27];
char rc[27];

void preorder(char i) {
    int num=i-'A'+1;
    cout<<i;
    if(lc[num]!='.') {
        preorder(lc[num]);
    }
    if(rc[num]!='.') {
        preorder(rc[num]);
    }
}
void inorder(char i) {
    int num=i-'A'+1;
    if(lc[num]!='.') {
        inorder(lc[num]);
    }
    cout<<i;
    if(rc[num]!='.') {
        inorder(rc[num]);
    }
}
void postorder(char i) {
    int num=i-'A'+1;
    if(lc[num]!='.') {
        postorder(lc[num]);
    }
    if(rc[num]!='.') {
        postorder(rc[num]);
    }
    cout<<i;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        char pa,u,v;
        cin>>pa>>u>>v;
        int numpa=pa-'A'+1;
        lc[numpa]=u;
        rc[numpa]=v;
         
    }
    preorder('A');
    cout<<'\n';
    inorder('A');
    cout<<'\n';
    postorder('A');
}