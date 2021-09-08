#include <bits/stdc++.h>

using namespace std;

long long sol(char c, long long a, long long b){
  if(c == '+')return a+b;
  if(c == '-')return a-b;
  if(c == '*') return a*b;
}

long long ex(char c1, char c2, char c3, vector<long long> a, vector<char> b){
  for(int i = 0; i<b.size(); i++){
    if(b[i] == c1){
      long long solve = sol(c1,a[i],a[i+1]);
      a.erase(a.begin()+i+1);
      b.erase(b.begin()+i);
      a[i] = solve;
      i--;
    }
  }
  for(int i = 0; i<b.size(); i++){
    if(b[i] == c2){
      long long solve = sol(c2,a[i],a[i+1]);
      a.erase(a.begin()+i+1);
      b.erase(b.begin()+i);
      a[i] = solve;
      i--;
    }
  }
  for(int i = 0; i<b.size(); i++){
    if(b[i] == c3){
      long long solve = sol(c3,a[i],a[i+1]);
      a.erase(a.begin()+i+1);
      b.erase(b.begin()+i);
      a[i] = solve;
      i--;
    }
  }
  return a[0];
}

long long solution(string s) {
  long long answer = 0;
  vector<long long> a;
  vector<char> b;
  
  string s2="";
  
  for(int i = 0; i<s.size(); i++){
    if(s[i] == '*' || s[i] == '+' || s[i] == '-'){
      a.push_back(stoll(s2));
      s2="";
      b.push_back(s[i]);
    } 
    else s2+=s[i];
  }
  a.push_back(stoll(s2));
  answer = max(abs(ex('+','-','*',a,b)),abs(ex('+','*','-',a,b)));
  answer = max(answer,abs(ex('-','+','*',a,b)));
  answer = max(answer,abs(ex('-','*','+',a,b)));
  answer = max(answer,abs(ex('*','+','-',a,b)));
  answer = max(answer,abs(ex('*','-','+',a,b)));
  return answer;
}