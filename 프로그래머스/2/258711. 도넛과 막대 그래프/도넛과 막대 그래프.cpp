#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    unordered_map<int,int> findCenter;
    for(auto v:edges) {
        findCenter[v[0]]++;
        
    }
    for(auto v:edges) {
        if(findCenter.find(v[1])!=findCenter.end()) {
            findCenter.erase(v[1]);
        }
        
    }
    int cnt=0;
    for(auto s:findCenter) {
        if(s.second>cnt) {
            cnt=s.second;
            answer[0]=s.first;
        }
    }
    
    vector<int> startNodes;
    unordered_map<int,int> Nodes;
    for(int i=0;i<edges.size();i++) {
        if(edges[i][0]==answer[0]) {
            startNodes.push_back(edges[i][1]);
        }
        else {
            if(Nodes.find(edges[i][0])==Nodes.end())
                Nodes[edges[i][0]]=edges[i][1];
            else {
                answer[3]++;
                Nodes.erase(edges[i][0]);
            }
        }
        
    }
    
    for(auto s:startNodes) {
    if(Nodes.find(s) == Nodes.end()) {
        continue;
    }
    
    int nxt = Nodes[s];
    while(nxt != 0) { // 0이 아닐 때까지 계속 루프를 실행
        if(Nodes.find(nxt) == Nodes.end()) {
            break; // 다음 노드가 없으면 탈출
        }
        if(nxt == s) {
            answer[1]++; // 도넛 그래프를 찾은 경우, 카운트를 증가시키고 탈출
            break;
        }
        nxt = Nodes[nxt]; // 다음 노드로 이동
    }
}

    answer[2]=cnt-answer[3]-answer[1];
    return answer;
}