#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1,q2;
    long long sum1=0,sum2=0;
    
    for(int i : queue1){
        sum1+=i;
        q1.push(i);
    }

    for(int i : queue2){
        sum2+=i;
        q2.push(i);
    }

    long long a=0,b=0;
    int maxindex = queue1.size()+queue2.size();
    int answer = 0;

    while(a < maxindex && b < maxindex){
        if (sum1 == sum2){
            return answer;
        }

        answer++;

        if(sum1<sum2){
            int c = q2.front();
            q2.pop();
            q1.push(c);
            sum2-=c;
            sum1+=c;
            a++;
        }
        else{
            int c = q1.front();
            q1.pop();
            q2.push(c);
            sum1-=c;
            sum2+=c;
            b++;
        }
    }

    return -1;
}

int main(){
    int a = 0;
    vector<int> queue1={3, 2, 7, 2};
    vector<int> queue2={4, 6, 5, 1};
    cout<<solution(queue1,queue2);
    return 0;
}