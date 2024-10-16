#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
int n;
unordered_map<string,int> c2ind;
int arr[10000][10000];
int vis[10000][10000];
string ind2c[1000];

vector<string> tmp;
int tot;
bool isEnd;
vector<string> answer;
void dfs(int ind, int cnt) {
    if(isEnd) return;
    if(cnt==n) {
        isEnd=true;
        //answer=tmp;
        answer.assign(tmp.begin(),tmp.end());
        return;
    }
    for(int i=0;i<tot;i++) {
        if(arr[ind][i]!=0) {
            arr[ind][i]--;
            tmp.push_back(ind2c[i]);
            dfs(i,cnt+1);
            tmp.pop_back();
            arr[ind][i]++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    n=tickets.size();
    
    vector<string> cities;
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            cities.push_back(tickets[i][j]);
        }
    }
    sort(cities.begin(),cities.end());
    cities.erase(unique(cities.begin(),cities.end()),cities.end());
    tot=cities.size(); //도시 개수
    int ind=0;
    int st;
    for(auto s:cities) {
        cout<<s<<' ';
        if(s=="ICN") st=ind;
        ind2c[ind]=s;
        c2ind[s]=ind++;
        
    }
    for(auto s:tickets) {
        int from=c2ind[s[0]];
        int to=c2ind[s[1]];
        // cout<<from<<' '<<to<<'\n';
        // cout<<ind2c[from]<<' '<<ind2c[to]<<'\n';
        arr[from][to]+=1; //같은 항공권이 여러개 나올 수 있었음..ㅠㅠ
    }
    tmp.push_back("ICN");
    dfs(st,0);
    return answer;
}

