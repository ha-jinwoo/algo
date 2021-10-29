#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    int size=pq.size();
    while(pq.top()<K){
        long long int a= pq.top();
        pq.pop();
        long long int b= pq.top();
        pq.pop();
        pq.push(a+2*b);
        if(pq.size()==1)break;
    }
    if(pq.size()==1&&pq.top()<K)return -1;
    return answer=size-pq.size();
}