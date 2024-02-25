#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     int t,k;
     int node;
     string ord;
    cin >> t;
    while (t--) {
        cin >> k;
        multiset<int> ms;
        while(k--) {
            cin>>ord>>node;
            if(ord=="I") {
                ms.insert(node);
            }
            else if(ms.size()) {
                if(node==1) {
                    auto max=ms.end();
                    max--;
                    ms.erase(max);
                }
                else if (node==-1) {
                    ms.erase(ms.begin());
                }
            }
        }
        if(!ms.size())
            cout<<"EMPTY"<<'\n';
        
        else {
            auto last=ms.end();
            last--;
            cout<<*last<<' '<<*ms.begin()<<'\n';
        } 
       
    }
}