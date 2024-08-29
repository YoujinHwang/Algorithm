#include <iostream>
using namespace std;
int arr[100][100];
int N,L;
int vis[100][100];

int chk_r(int x) { //각 행을 살피는 경우 
    //int tmp=arr[x][0];
    int cnt=1;
    bool need=false;
    for(int i=1;i<N;i++) {
        if (arr[x][i]-arr[x][i-1]==0) {
            cnt++;
            
            if(cnt>=L&&need) {
                need=false;
                // cout<<"stair: "<<i<<'\n';
                cnt=cnt-L;
            }
            // else if(cnt==L)
        }
        else if(arr[x][i]-arr[x][i-1]==-1) { //앞으로 다리를 놓아야함
            if(cnt==L&&need) { 
                need=false;
                cnt=1; //이 칸 위에 다리 놓음-> 0
            }
            else if(cnt<L&&need) { //다리를 놓아야하는 상황인데 단차가 더 내려간 경우
                return -1;
            }
           cnt=1;
            need=true;
            if(L==1) {
                need=false;
                cnt=0;
            } 
            
        }
        else if(arr[x][i]-arr[x][i-1]==1) {
            if(cnt<L) { //이전에 다리를 놓아야함
                return -1;
            }
            cnt=1;
        }
        else { //높이가 2 이상 차이나서 다리를 놓을 수 없는 경우
            return -1;
        }
    }
    
    if (cnt<L&&need) return -1; //다리를 놓지 못한 상태로 끝나버린 경우
    return 0;
}

int chk_c(int x) { //각 열을 살피는 경우 
    //int tmp=arr[x][0];
    int cnt=1;
    bool need=false;
    for(int i=1;i<N;i++) {
        if (arr[i][x]-arr[i-1][x]==0) {
            cnt++;
            // cout<<cnt<<'\n';
            if(cnt>=L&&need) {
                // cout<<"stair: "<<i<<'\n';
                need=false;
                cnt=cnt-L;
            }
            
            // else if(cnt==L)
        }
        else if(arr[i][x]-arr[i-1][x]==-1) { //앞으로 다리를 놓아야함
            
            if(cnt==L&&need) { 
                need=false;
                cnt=1; //이 칸 위에 다리 놓음-> 0
            }
            else if(cnt<L&&need) { //다리를 놓아야하는 상황인데 단차가 더 내려간 경우
                return -1;
            }
           cnt=1;
            need=true;
            if(L==1) {
                need=false;
                cnt=0;
            } 
           
        }
        else if(arr[i][x]-arr[i-1][x]==1) {
            if(cnt<L) { //이전에 다리를 놓아야함
                return -1;
            }
            cnt=1;
        }
        else { //높이가 2 이상 차이나서 다리를 놓을 수 없는 경우
            return -1;
        }
    }
    if (cnt<L&&need) return -1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L;
    int ans=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>arr[i][j];
        }
        if(chk_r(i)==0) {
            ans++;
            //  cout<<"r: "<<i<<'\n';
        } 
        
    }
    
    for(int i=0;i<N;i++) {
        if(chk_c(i)==0) {
            ans++;
            //  cout<<"c: "<<i<<'\n';
        } 
    }
    //  cout<<'\n';
    cout<<ans;
}