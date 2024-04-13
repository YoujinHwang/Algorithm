#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<string> alphas = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string w;
    cin>>w;
    for(auto alpha:alphas) {
        while(true) {
            int pos=w.find(alpha);
            if(pos==string::npos) break;
            w.replace(pos,alpha.size(),"a");
        }
    }
    cout<<w.size();
}