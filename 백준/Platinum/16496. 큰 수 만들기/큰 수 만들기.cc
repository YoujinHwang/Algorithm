#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 두 문자열을 합쳤을 때 더 큰 조합이 앞에 오도록 비교하는 함수
bool cmp(const string &a, const string &b) {
    return a + b > b + a; // 두 문자열을 이어붙여 비교
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<string> numbers; // 모든 문자열을 저장할 벡터
    
    // 입력 처리
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        numbers.push_back(str); // 모든 문자열을 하나의 벡터에 저장
    }
    
    // 모든 문자열이 "0"인 경우 예외 처리
    if (all_of(numbers.begin(), numbers.end(), [](const string &s) { return s == "0"; })) {
        cout << 0;
        return 0;
    }
    
    // 문자열을 cmp 기준으로 정렬 (두 문자열을 이어붙여서 더 큰 쪽이 앞에 오도록)
    sort(numbers.begin(), numbers.end(), cmp);
    
    // 가장 큰 숫자를 만들기 위한 결과 문자열 생성
    string ans;
    for (const string &str : numbers) {
        ans += str; // 정렬된 문자열을 결과에 추가
    }
    
    cout << ans; // 결과 출력
    return 0;
}