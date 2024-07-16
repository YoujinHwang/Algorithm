#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define X first 
#define Y second
int solution(string begin, string target, vector<string> words) {
    
    int answer = 0;
    int n=words.size();
    int len=begin.size();
    int vis[51]={0};
    queue<pair<int,string>> q;
    q.push({50,begin});
    while(!q.empty()) {
        pair<int,string> cur=q.front();
        q.pop();
        int cur_ind=cur.X;
        string cur_word=cur.Y;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<len;j++) {
                if(cur_word[j]!=words[i][j]) cnt++;
                if(cnt>1) break;
            }
            if(cnt>1) continue;
            if(cnt==1&&vis[i]==0) {
                q.push({i,words[i]});
                vis[i]=vis[cur_ind]+1;
                if(words[i]==target) {
                    answer=vis[i];
                    return answer;
                }
                
            } 
        }
//         int cnt=0;
//         for(int j=0;j<len;j++) {
//             if(cur_word[j]!=target[j]) cnt++;
//             if(cnt>1) break;
//         }
        
//         if(cnt==1) {
//             // q.push(i,words[i]);
//             answer=vis[cur_ind]+1;
//             break;
//         } 
    }
    return 0;
    // return answer;
}