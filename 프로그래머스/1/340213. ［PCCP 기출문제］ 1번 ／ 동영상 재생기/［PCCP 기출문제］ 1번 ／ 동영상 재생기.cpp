#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int m=stoi(pos.substr(0,pos.find(':')));
    int s=stoi(pos.substr(pos.find(':')+1));
    int cur=m*60+s;
     int st_m=stoi(op_start.substr(0,op_start.find(':')));
    int st_s=stoi(op_start.substr(op_start.find(':')+1));
    int op_st=st_m*60+st_s;
     int en_m=stoi(op_end.substr(0,op_end.find(':')));
    int en_s=stoi(op_end.substr(op_end.find(':')+1));
    int op_en=en_m*60+en_s;
    //cout<<op_st<<' '<<op_en<<'\n';
    int vi_m=stoi(video_len.substr(0,video_len.find(':')));
    int vi_s=stoi(video_len.substr(video_len.find(':')+1));
    int vi=vi_m*60+vi_s;
    
    if(cur<op_en&&cur>=op_st) cur=op_en;
    for(auto c:commands) {
        if(c=="next") {
            cur+=10;
        }
        else {
            cur-=10;
        }
        if (cur<0) cur=0;
        if(cur<op_en&&cur>=op_st) cur=op_en;
        else if(cur>vi) cur=vi;
    //printf("%02d %02d\n",cur/60, cur%60);
        
        //cout<<cur<<'\n';
        
    }
    string mm=to_string(cur/60);
    string ss=to_string(cur%60);
    if(mm.size()==1) mm="0"+mm;
    if(ss.size()==1) ss="0"+ss;
    answer=mm+':'+ss;
    return answer;
}