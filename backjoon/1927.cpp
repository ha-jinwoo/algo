// 최소 힙
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,m;
  cin>>n;
  priority_queue <int, vector<int>, greater<int> > pq;
  while(n--){
    cin>>m;
    if(!m){
      if(!pq.size()) cout<<"0"<<"\n"; 
      else{
        cout<<pq.top()<<"\n";
        pq.pop();
      } 
    }
    else pq.push(m);
  }
  return 0;
}