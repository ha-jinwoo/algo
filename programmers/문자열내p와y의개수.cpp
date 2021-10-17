#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == 'p' || s[i]== 'P')cnt1++;
        else if(s[i]=='y' || s[i]=='Y')cnt2++;
    }
    return cnt1==cnt2;
}