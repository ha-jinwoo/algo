#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> s2;
    for(int i = 0; i<s.size(); i++){
        s2.push_back(s[i]);
    }
    sort(s2.begin(),s2.end());
    reverse(s2.begin(),s2.end());
    for(int i = 0; i<s2.size(); i++){
        answer+=s2[i];
    }
    return answer;
}