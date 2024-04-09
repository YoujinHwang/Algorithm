#include <string>
#include <vector>
#include <climits>

using namespace std;
//bool isPos;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int min=INT_MAX;
    int min_st=0,min_en=0;
    int st,en=0;
    int sum=0,cnt=0;
    for(int i=0;i<sequence.size();i++) {
        // if(i!=0) {
        //     sum-=sequence[st];
        //     cnt--;
        // }
        // if(!isPos) {
        //     sum-=sequence[en];
        //     cnt--;
        // }
        st=i;
        
        while(en<=sequence.size()) {
            
            if(sum==k) {
                //isPos=true;
                //en++;
                if(cnt<min) {
                    min=cnt;
                    min_st=st;
                    min_en=en-1;
                }
                break;
            }
            else if(sum>k) {
                //isPos=false;
               // en--;
                break;
            }
            if(en==sequence.size()) break;
            sum+=sequence[en];
            cnt++;
            en++;
        }
        sum-=sequence[st];
        cnt--;
        
    }
    answer.push_back(min_st);
    answer.push_back(min_en);
    return answer;
}

// #include <string>
// #include <vector>
// #include <climits>

// using namespace std;

// vector<int> solution(vector<int> sequence, int k) {
//     vector<int> answer;
//     int min_length = INT_MAX;
//     int min_st = -1, min_en = -1;
//     int st = 0, en = 0;
//     int sum = 0;

//     while (en <= sequence.size()) {
//         if (sum < k) {
//             if (en == sequence.size()) break; // 끝에 도달했으나 합이 k보다 작은 경우
//             sum += sequence[en++];
//         } else if (sum >= k) {
//             if (sum == k && (en - st < min_length)) {
//                 min_length = en - st;
//                 min_st = st;
//                 min_en = en - 1;
//             }
//             sum -= sequence[st++];
//         }
//     }

//     if (min_st == -1) {
//         // 조건을 만족하는 부분 배열이 없는 경우
//         return {-1, -1};
//     } else {
//         answer.push_back(min_st);
//         answer.push_back(min_en);
//         return answer;
//     }
// }
