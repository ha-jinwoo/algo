#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i<=2500; i++){
        for(int j =1; j<=i; j++){
            if(i*j == brown + yellow && (i-2) * (j-2) == yellow ){
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
    return answer;
}