#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("Input.txt", "r", stdin);
  vector<string> result;
  string b;
  while(1){
    cin>>b; 
    if(b == "0")break;
    string c = b;
    reverse(b.begin(),b.end());
    if(b==c)result.push_back("yes");
    else result.push_back("no");
  }
  for(string c : result)cout<<c<<endl;
  return 0;
}