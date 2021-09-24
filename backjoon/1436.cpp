#include <bits/stdc++.h>

using namespace std;

bool is666(string s){
  for(int i = 0; i<=s.size()-3; i++)
    if(s[i]=='6'&&s[i+1]=='6'&&s[i+2]=='6')return true;
  return false;
}


int main(){
  freopen("Input.txt", "r", stdin);
  int n;
  cin>>n;
  vector<int> result;
  for(int i = 666; ; i++){
    if(is666(to_string(i))){
      n--;
      if(n==0){
        cout<<i;
        break;
      }
    }
  }
  return 0;
}