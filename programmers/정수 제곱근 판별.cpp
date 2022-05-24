#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    long long k = 10000000000000;
    cout<<sqrt(k);
    if((long long)sqrt(n)*(long long)sqrt(n) == n)return ((long long)sqrt(n)+1)*((long long)sqrt(n)+1);
    else return -1;
}