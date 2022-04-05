#include <bits/stdc++.h>

using namespace std;

bool space(char c){return isspace(c);}
bool not_space(char c){return !isspace(c);}
vector<string> split(const string& str){
  vector<string> ret;
  string::const_iterator it_b = str.begin();
  while (it_b != str.end()){
    it_b = find_if(it_b, str.end(), not_space);
    string::const_iterator it_e = find_if(it_b, str.end(), space);
    if (it_b != str.end()) ret.push_back(string(it_b, it_e));
    it_b = it_e;
  }
  return ret;
}


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    string repo = "";
    unordered_map<string,int> attributes;
    unordered_map<string,vector<string>> attributes2;
    
    sort(report.begin(),report.end());
    for(int i = 0; i<report.size(); i++) {
      if(repo == report[i]) continue;
      else{
        repo = report[i];
        vector<string> name = split(report[i]);
        attributes[name[1]]++;
        attributes2[name[0]].push_back(name[1]);
        // for(auto it=attributes.begin();it!=attributes.end();it++) cout<<it->first<<" "<<it->second;
        // cout<<endl;
      }
    }
    for(string id : id_list){
      int Emailcount = 0;
      for(string reid : attributes2[id]) {
        if(attributes[reid] >= k) Emailcount++;
      }
      answer.push_back(Emailcount);
    }
    // for(auto it=attributes.begin();it!=attributes.end();it++) cout<<it->first<<" "<<it->second;
    return answer;
}

int main(){
  vector <int> result = solution({"muzi", "frodo", "apeach", "neo"},{"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"},2);
  for(int i : result)cout<<i<<" ";
  return 0;
}
