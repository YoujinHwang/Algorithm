// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;
// bool isUsed[15];
// int idx=0;
// // int hp;
// int Min=1250;
// int n;
// vector<int> tool;

// void use(vector<string>& minerals,int hp) {
//     int n=minerals.size();
    
//     if(idx==n) {
//         Min=min(Min, hp);
//         hp=0;
//         return;
//     }
    
//     for(int j=0;j<tool.size();j++) {
//         if(isUsed[j]) continue;
//         int x,y,z;
//         isUsed[j]=true;
//         if(tool[j]==0) {
//             x=1;
//             y=1;
//             z=1;
//         }
//         else if(tool[j]==1) {
//             x=5;
//             y=1;
//             z=1;
//         }
//         else if(tool[j]==2) {
//             x=25;
//             y=5;
//             z=1;
//         }
//         if(minerals[idx++]=="diamond") {
//             hp+=x;
//         }
//         else if(minerals[idx++]=="iron") {
//             hp+=y;
//         }
//         else if(minerals[idx++]=="stone") {
//             hp+=z;
//         }
//         use(minerals,hp);
//         idx--;
//         isUsed[j]=false;
//     }
//     Min=min(Min,hp);
//     hp=0;
//     return;
// }

// int solution(vector<int> picks, vector<string> minerals) {
//     int answer = 0;
//     while(picks[0]--) {
//         tool.push_back(0);
//     }
//     while(picks[1]--) {
//         tool.push_back(1);
//     }
//     while(picks[2]--) {
//         tool.push_back(2);
//     }
//     use(minerals,0);
//     answer=Min;
//     return answer;
// }

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = INT32_MAX;

int cnt_tired(int cnt, int idx, vector<int> mine)
{
    int pick = (int)pow(5,2-idx), res = 0;
    // pick : 다이아 = 25, 철 = 5, 돌 = 1
    for(int i=cnt*5;i<(cnt+1)*5 && i<mine.size();i++)
    {
        int num = mine[i] / pick;//광물을 곡괭이값으로 나눈값이 표에있는값이다.
        if (num == 0) res++;// 곡괭이가 크면 0이기때문에
        else res += num;
    }
    return res;
}

void    dfs(int cnt, int res, vector<int> picks, vector<int> mine)
{
    if ((!picks[0] && !picks[1] && !picks[2]) || cnt*5 >= mine.size())// 곡괭이를 다 썻거나, 광물을 다 캤으면
    {
        answer = min(answer, res);// 최소값 저장
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(picks[i])
        {
            picks[i]--;//곡괭이 개수--
            dfs(cnt+1, res+cnt_tired(cnt,i,mine), picks, mine);
            picks[i]++;//dfs넘겨주고 다시++
        }
    }
}
int solution(vector<int> picks, vector<string> minerals)
{
    vector<int> mine;
    for(auto c : minerals)
    {// 광물 : 다이아 = 25, 철 =5, 돌 =1 로 새로운 vector에 저장
        if(c[0]=='d') mine.push_back(25);
        else if(c[0]=='i') mine.push_back(5);
        else mine.push_back(1);
    }
    dfs(0, 0, picks, mine);
    return answer;
}