#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    int a;
    while(n > 0){
        n = n / 3;
        if (n % 3 == 0){
            n -= 1;
        }
        answer = "412"[a] + answer;
    }
    return answer;
}