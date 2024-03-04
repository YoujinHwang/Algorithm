#include <string>
#include <vector>

using namespace std;
unordered_set<string,int> type;

vector<string> split(string& s, string& sep) {
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
    int yy=stoi(dt[0]);
    int mm=stoi(dt[1]);
    int dd=stoi(dt[2]);
    
    for(auto a:terms) {
        vector<string> tm=split(a," ");
        type.insert({tm[0],stoi(tm[1])});
        cout<<tm[0]<<" "<<tm[1];
    }
    
    
    return answer;
}