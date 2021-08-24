//직사각형에서 탈출

#include <bits/stdc++.h>

using namespace std;

vector<string> vs;

bool op(string a, string b){
  if(a.size()==b.size()){
        return a<b;
    }else{
        return a.size()<b.size();
    }
}

int main(){
  freopen("Input.txt", "r", stdin);

  string s;
  int n;
  cin>>n;

  for(int i = 0; i<n; i++){
    cin>>s;
    vs.push_back(s);
  }

  sort(vs.begin(),vs.end(),op);
  vs.erase(unique(vs.begin(), vs.end()), vs.end());

  for(int i = 0; i<vs.size(); i++){
    cout<<vs[i]<<endl;
  }

  return 0;
}