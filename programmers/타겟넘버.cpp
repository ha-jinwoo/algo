#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
void dfs(vector<int> numbers, int target,int i,int re){
    if(i==numbers.size()){if(re==target)answer++;return;}
    dfs(numbers,target,i+1,re+numbers[i]);
    dfs(numbers,target,i+1,re-numbers[i]);
}
int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    return answer;
}