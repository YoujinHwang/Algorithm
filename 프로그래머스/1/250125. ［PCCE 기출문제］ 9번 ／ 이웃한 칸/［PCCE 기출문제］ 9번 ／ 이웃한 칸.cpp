#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n;
    n=board.size();
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    for(int i=0;i<4;i++) {
        int nx=h+dx[i];
        int ny=w+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(board[nx][ny]==board[h][w])
            answer++;
    }
    
    return answer;
}