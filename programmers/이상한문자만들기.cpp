#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

string solution(string s2) {
    string answer = "";
    vector<string> ss = split(s2, ' ');
    for(string s : ss){
        cout<<s<<endl;
        for(int i = 0; i<s.size(); i++){
            if(i%2==0)answer+=toupper(s[i]);
            else answer+=tolower(s[i]);
        }
        answer+=" ";
    }
    if(ss.size()>=1)answer.erase(answer.size()-1, 1);
    return answer;
}