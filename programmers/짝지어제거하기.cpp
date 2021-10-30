#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    stack<char> c;
    for(int i = 0; i<s.size(); i++){
        if(c.empty()){
            c.push(s[i]);
            continue;
        }
        if(c.top() == s[i]){
            c.pop();
        }
        else c.push(s[i]);
    }
    if(c.empty())return 1;
    else return 0;
}