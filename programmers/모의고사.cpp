#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    int counta = 0 ,countb = 0, countc = 0;
    
    vector<int> answer;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++){
        if(a[i%a.size()] == answers[i])counta++;
        if(b[i%b.size()] == answers[i])countb++;
        if(c[i%c.size()] == answers[i])countc++;
    }
    
    int max2 = max(counta,countb);
    max2 = max(max2,countc);
    
    if(max2 == counta)answer.push_back(1);
    if(max2 == countb)answer.push_back(2);
    if(max2 == countc)answer.push_back(3);
    
    return answer;
}