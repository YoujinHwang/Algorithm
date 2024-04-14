#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size()==4||s.size()==6) {
        for(auto a:s) {
            if(!isdigit(a)){
                answer=false;
                return answer;
            }
        }
    }
    else answer=false;
    return answer;
}