// #include <string>
// #include <vector>
// #include <stack>

// using namespace std;
// bool isPos; 

// int solution(string s) {
//     int answer = 0;
//     int n=s.size();
//     for(int i=0;i<n;i++) {
//         stack<char> st;
//         isPos=true;
//         for(auto a: s) {
//             if(a=='('||a=='['||a=='{')
//                 st.push(a);
//             else {
//                 if(st.empty()) {
//                     isPos=false;
//                     break;
//                 }
//                 char cur=st.top();
//                 if(a==')') {
//                     if(cur!='(') {
//                         isPos=false;
//                         break;
//                     }
//                 }
//                 else if(a==']') {
//                     if(cur!='[') {
//                         isPos=false;
//                         break;
//                     }
//                 }
//                 else if(a=='}') {
//                     if(cur!='{') {
//                         isPos=false;
//                         break;
//                     }
//                 }
//                 st.pop();
//             }
//         }
//         if(!st.empty()) isPos=false;
//         if (isPos) answer++; //if(!isPos) continue; 로 해서 틀렸는데, 이러면 !isPos인 경우에는 아래 괄호가 회전하는 코드가 작동하지 않아서 코드 회전이 이루어지지 않는다. 항상 회전되어야 하므로 이렇게 고치는게 맞다. 
//         char x=s[0];
//         s.erase(s.begin());
//         s.push_back(x);
//     }
//     return answer;
// }



#include <string>
#include <vector>
#include <stack>
using namespace std;

string rotate(string str) {
    string res = str;
    char tmp = res[0];
    res.erase(0, 1);
    res.push_back(tmp);
    return res;
}

bool isCorrect(string str) {
    stack<char> st;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else {
            if(st.empty()) return false;
            else {
                if(st.top() == '(' && str[i] == ')') st.pop();
                else if(st.top() == '{' && str[i] == '}') st.pop();
                else if(st.top() == '[' && str[i] == ']') st.pop();
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    if(isCorrect(s)) answer++; 
    for(int i = 1; i < s.size(); i++) {
        s = rotate(s);
        if(isCorrect(s)) answer++;
    }
    return answer;
}