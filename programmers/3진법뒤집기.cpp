#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s="";
    while(1){
        s+=n%3;
        n/=3;
        if(n==0)break;
    }
    cout<<s;
    for(int i = s.size()-1, k = 1; i>=0; i--){
        answer+=s.at(i) * k;
        k*=3;
    }
    return answer;
}