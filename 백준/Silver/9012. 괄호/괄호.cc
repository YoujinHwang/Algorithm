#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        bool isPos=true;
        string st;
        cin>>st;
        queue<char> q;
        for(int i=0;i<st.size();i++) {
            if(st[i]=='(') {
                q.push(st[i]);
            }
            else { 
                if(!q.empty()) {
                    if(q.front()=='(') {
                        q.pop();
                    }
                    else {
                        isPos=false;
                        // cout<<"NO"<<'\n';
                        break;
                    }
                }
                else {
                    isPos=false;
                    // cout<<"NO"<<'\n';
                    break;
                }
                
            }

        }
        if(isPos&&q.size()==0) {
            cout<<"YES"<<'\n';
        }
        else {
            cout<<"NO"<<"\n";
        }
        
    }

}