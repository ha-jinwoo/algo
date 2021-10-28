#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int maxday = 0;
    for(int i = 0; i<progresses.size(); i++){
        int day;
        if((100-progresses[i]) % speeds[i] == 0) day = (100-progresses[i]) / speeds[i];
        else day = (100-progresses[i]) / speeds[i] + 1;
        if(maxday < day){
            maxday = day;
            answer.push_back(1);
        }
        else answer.back()++;
    }
    return answer;
}