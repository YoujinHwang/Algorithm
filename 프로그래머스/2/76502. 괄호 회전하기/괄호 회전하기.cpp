#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isPos; 

int solution(string s) {
    int answer = 0;
    int n=s.size();
    for(int i=0;i<n;i++) {
        stack<char> st;
        isPos=true;
        for(auto a: s) {
            if(a=='('||a=='['||a=='{')
                st.push(a);
            else {
                if(st.empty()) {
                    isPos=false;
                    break;
                }
                char cur=st.top();
                if(a==')') {
                    if(cur!='(') {
                        isPos=false;
                        break;
                    }
                }
                else if(a==']') {
                    if(cur!='[') {
                        isPos=false;
                        break;
                    }
                }
                else if(a=='}') {
                    if(cur!='{') {
                        isPos=false;
                        break;
                    }
                }
                st.pop();
            }
        }
        if(!st.empty()) isPos=false;
        if (isPos) answer++;
        char x=s[0];
        s.erase(s.begin());
        s.push_back(x);
    }
    return answer;
}