#include <string>
#include <vector>

using namespace std;

// vector<string> Split(string& s, const string& sep) {
//     vector<string> ret;
//     int pos=0;
//     while(pos<s.size()) {
//         int nxt_pos=s.find(sep, pos);
//         if(nxt_pos==-1) nxt_pos=s.size();
//         if(nxt_pos-pos>0) 
//             ret.push_back(s.substr(pos,nxt_pos-pos));
//         pos=nxt_pos+sep.size();
//     }
//     return ret;
// }

// using namespace std;

// string solution(string s) {
//     string answer = "";
//     vector<string> ret;
//     ret=Split(s," ");
//     for(auto x:ret) {
//         for(int i=0;i<x.size();i++) {
//             if(i%2==0) {
//                 answer+=toupper(x[i]);
//             }
//             else answer+=tolower(x[i]);
//         }
//         answer+=' ';
//     }
//     if(!answer.empty()) answer.pop_back();
//     return answer;
// }
//위의 코드는 공백 문자가 두 개 이상 연속으로 오는 경우를 해결하지 못한 것 같음

string solution(string s) {
    string answer ="";
    int count =0;
    for(int i=0;i<s.size();i++) {
        if(s[i]==' ') {
            count=0;
            answer+=' ';
            continue;
        }
        if(count%2==0) {
            answer+=toupper(s[i]);
            count++;
        }
        else {
            answer+=tolower(s[i]);
            count++;
        }
    }
    return answer;
}
