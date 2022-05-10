#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    int cnt = 1;
    long long sum = 0;
    while(1){
        sum+=price*cnt;
        if(cnt==count)break;
        cnt++;      
    }
    if(money>=sum)return 0;
    else return sum-money;
}