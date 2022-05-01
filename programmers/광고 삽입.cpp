#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

// 시간 문자열을 초 단위로 변환하는 함수
int timeToSeconds(const string& time) {
    int hours = (time[0]-'0')*10 + (time[1]-'0');
    int minutes = (time[3]-'0')*10 + (time[4]-'0');
    int seconds = (time[6]-'0')*10 + (time[7]-'0');
    return hours*3600 + minutes*60 + seconds;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int seconds[360000];
    memset(seconds, 0, sizeof(seconds));
    for (auto& l : logs) {
        int start = timeToSeconds(l);
        int end = timeToSeconds(l.substr(9));
        for (int i = start; i < end; i++)
            seconds[i]++; // 끝 시간은 포함되지 않으므로 제외하고 재생 사람 수를 카운트
    }
    
    int playTime = timeToSeconds(play_time);
    int advTime = timeToSeconds(adv_time);
    int startTime = 0;
    ll sum = 0, maxSum;
    // 첫 광고시간동안 재생한 사람 수 누적합 계산
    for (int i = 0; i < advTime; i++) sum += seconds[i];
    maxSum = sum;
    // 한 칸씩 윈도우를 옮기면서 최댓값 탐색
    for (int i = advTime; i < playTime; i++) {
        sum = sum - seconds[i-advTime] + seconds[i];
        if (sum > maxSum) {
            startTime = i-advTime+1; // 최댓값이면 시작 시각 저장
            maxSum = sum;
        }
    }
    
    // 초 단위를 다시 문자열 포맷으로 변환
    string answer;
    int times[3] = {startTime / 3600, (startTime % 3600) / 60, (startTime % 3600) % 60};
    for (int i = 0; i < 3; i++) {
        int a = times[i] / 10, b = times[i] % 10;
        answer.push_back(a + '0');
        answer.push_back(b + '0');
        if (i < 2) answer.push_back(':');
    }
    
    return answer;
}