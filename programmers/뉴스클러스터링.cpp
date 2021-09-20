#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
  int answer = 0;
  int bunmo = 0;
  int bunja = 0;
  unordered_map<string,int> s1;
  unordered_map<string,int> s2;

  for(int i = 0; i<str1.size()-1; i++)
    if(isalpha(str1[i])&&isalpha(str1[i+1])){
      string s = "";
      s+=tolower(str1[i]);
      s+=tolower(str1[i+1]);
      s1[s]++;
      bunmo++;
    }

  for(int i = 0; i<str2.size()-1; i++)
    if(isalpha(str2[i])&&isalpha(str2[i+1])){
      string s = "";
      s+=tolower(str2[i]);
      s+=tolower(str2[i+1]);
      s2[s]++;
      bunmo++;
    }
  
  for(auto it=s1.begin();it!=s1.end();it++) bunja+=min(it->second,s2[it->first]);

  bunmo -= bunja;
  if (bunmo == 0) {
    answer = 65536;
  }
  else {
    answer = bunja * 65536 / bunmo;
  }
  return answer;
}