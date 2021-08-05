// 최소 힙
#include <bits/stdc++.h>

using namespace std;

int main(){
  // freopen("Input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,m,r;
  cin>>n;
  priority_queue <int, vector<int>, greater<int> > pq;
  while(n--){
    cin>>m;
    if(!m){
      if(!pq.size()) cout<<"0"<<endl; 
      else{
        cout<<pq.top()<<endl;
        pq.pop();
      } 
    }
    else pq.push(m);
  }
  return 0;
}