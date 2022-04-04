#include <bits/stdc++.h>

using namespace std;

char p[3] = {'a','b','c'};

void sol(int n, vector<char> clist, vector<bool> visit){
  if(n == 3){
    for(char c : clist)cout<<c;
    cout<<endl;
    return;
  }
  
  for(bool b : visit) cout<<b<<" ";
  for(char c : clist) cout<<c<<" ";
  cout<<endl;

  for(int i = 0; i<3; i++){
    if(!visit[i]){
      visit[i] = true;
      clist.push_back(p[i]);
      sol(n+1,clist,visit);
      visit[i] = false;
      clist.pop_back();
    }
  }
}

int main() {

	vector<bool> visit(3,false);
  vector<char> c;
  sol(0,c,visit);
  return 0;
}