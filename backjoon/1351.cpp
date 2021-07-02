// 무한수열

#include <bits/stdc++.h>

using namespace std;

long long int N,P,Q;
map<long long int, long long int> cache;

long long int dfs(long long int i){
  if (cache.count(N)) return cache[N];
  return cache[N] = dfs(i/P) + dfs(i/Q);
}

int main(){
  // freopen("Input.txt", "r", stdin);
  cin>>N>>P>>Q;
  
  cache[0] = 1;
  cout << dfs(N);
  return 0;
}