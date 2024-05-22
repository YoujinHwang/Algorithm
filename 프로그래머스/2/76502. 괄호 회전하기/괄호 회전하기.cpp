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
        if (isPos) answer++; //if(!isPos) continue; 로 해서 틀렸는데, 이러면 !isPos인 경우에는 아래 괄호가 회전하는 코드가 작동하지 않아서 코드 회전이 이루어지지 않는다. 항상 회전되어야 하므로 이렇게 고치는게 맞다. 
        char x=s[0];
        s.erase(s.begin());
        s.push_back(x);
    }
    return answer;
}

