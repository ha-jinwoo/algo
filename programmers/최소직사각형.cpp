#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max1=0,max2=0;
    for(vector<int> a : sizes){    
        if(max1 < a[0]) max1 = a[0];
        if(max1 < a[1]) max1 = a[1];
    }

    for(vector<int> a : sizes){
        if(a[0]>a[1]){
            max2 = max(max2,a[1]);
        }else{
            max2 = max(max2,a[0]);
        }
    }
    return max1 * max2;
}