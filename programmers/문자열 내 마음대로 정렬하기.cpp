#include <bits/stdc++.h>

using namespace std;
int k;
bool comp(string a, string b){
    if(a[k]==b[k])return a<b;
    return a[k] < b[k];
}

vector<string> solution(vector<string> strings, int n) {
    k=n;
    sort(strings.begin(),strings.end(),comp);
    return strings;
}