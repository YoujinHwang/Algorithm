#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<string,int> type;

vector<string> split(string& s, string sep) {
    vector<string> ret;
    int pos=0;
    while(pos<s.size()) {
        int nxt_pos=s.find(sep,pos);
        if(nxt_pos==-1) nxt_pos=s.size();
        if(nxt_pos-pos>0) 
            ret.push_back(s.substr(pos,nxt_pos-pos));
        pos=nxt_pos+sep.size();
    }
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<string> dt=split(today, ".");
    int t_yy=stoi(dt[0]);
    int t_mm=stoi(dt[1]);
    int t_dd=stoi(dt[2]);
    
    for(auto a:terms) {
        vector<string> tm=split(a," ");
        type.insert({tm[0],stoi(tm[1])});
        //cout<<tm[0]<<" "<<tm[1]<<'\n';
    }
    for(auto a:type) cout<<a.first<<" "<<a.second<<'\n';
    for(int i=0;i<privacies.size();i++) {
        vector<string> p=split(privacies[i]," ");
        vector<string> date=split(p[0],".");
        int y=stoi(date[0]);
        int m=stoi(date[1]);
        int d=stoi(date[2]);
        
        int due_y=y;
        int due_m=m+type[p[1]];
        if(due_m>12) {
            int left=due_m-12;
            due_m=12;
            due_y+=left/12;
            if(left%12) {
                due_y++;
                due_m=left%12;
            }
        }
        if(due_y>t_yy) continue;
        else if(due_y==t_yy) {
            if(due_m>t_mm) continue;
            else if(due_m==t_mm) {
                if(d<=t_dd) {
                    answer.push_back(i+1);
                }
            }
            else answer.push_back(i+1);
        }
        else answer.push_back(i+1);
    }
    
    
    return answer;
}