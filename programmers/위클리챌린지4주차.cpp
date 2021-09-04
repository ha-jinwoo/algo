#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
  string answer = "";
  int max2=0;
  for(int i = 0; i<table.size(); i++){
    vector <string> s = split(table[i], ' ');
    int sum= 0;
    for(int i = 0; i<languages.size(); i++){
      for(int j = 0; j<s.size(); j++){
        if(s[j] == languages[i]){
          sum+=preference[i] * (s.size()-j);
        }
      }
    }
    if(sum > max2){
      answer = s[0];
      max2 = sum;
    }else if(sum == max2){
      if(answer > s[0])answer = s[0];
    }
    cout<<sum<<" ";
  }
  return answer;
}
int main()
{
  vector <string> table = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};
  vector<string> languages = {"JAVA", "JAVASCRIPT"};
  vector<int> preference = {7, 5};
  cout<<solution(table,languages,preference);
  return 0;
}