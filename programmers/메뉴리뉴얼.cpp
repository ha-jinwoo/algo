#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> attributes;

void combination(int kn,int kr,string s){
  vector<string> n;
  vector<int> ind;
  for (int i = 0; i < kn; i++) {
    string ss = "";
    ss += s[i];
    n.push_back(ss);
  }
  for(int i=0; i<kr; i++) ind.push_back(1);
  for(unsigned int i=0; i<n.size()-kr; i++) ind.push_back(0);
  sort(ind.begin(), ind.end());
  do{
    string s2 ="";
    for(unsigned int i=0; i<ind.size(); i++) if(ind[i] == 1) s2+=n[i];
    sort(s2.begin(), s2.end());
    attributes[s2]++;
  }while(next_permutation(ind.begin(), ind.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;
  for (string s : orders) {
    for (int j = 1; j <= s.size(); j++)
      combination(s.size(), j, s);
  }
  vector <int> v(11);
  for(int c:course){
    int max=0;
    for (auto it = attributes.begin(); it != attributes.end(); it++)
      if(it->first.size() == c && max<it->second) max=it->second;
    if(max>1)v[c]=max;
  }

  for(int i = 0; i<v.size(); i++){
    if(v[i]==0)continue;
    for (auto it = attributes.begin(); it != attributes.end(); it++)
      if(it->second == v[i] && it->first.size() == i ) answer.push_back(it->first);
  }
  sort(answer.begin(),answer.end());
  return answer;
}