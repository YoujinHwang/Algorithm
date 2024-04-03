#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int sort_idx;

bool cmp(vector<int>& a,vector<int>& b) {
    return a[sort_idx]<b[sort_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    int idx;
    vector<vector<int>> answer;
    if(ext=="code") {
        idx=0;
    }
    else if(ext=="date") {
        idx=1;
    }
    else if(ext=="maximum") {
        idx=2;
    }
    else if(ext=="remain") {
        idx=3;
    }
    
    if(sort_by=="code") {
        sort_idx=0;
    }
    else if(sort_by=="date") {
        sort_idx=1;
    }
    else if(sort_by=="maximum") {
        sort_idx=2;
    }
    else if(sort_by=="remain") {
        sort_idx=3;
    }
    
    for(auto s:data) {
        if(s[idx]<val_ext) answer.push_back(s);
    }
    sort(answer.begin(),answer.end(),cmp);
    return answer;
}