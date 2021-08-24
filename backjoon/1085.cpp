//직사각형에서 탈출

#include <bits/stdc++.h>

using namespace std;

int x,y,w,h;

int main(){
  freopen("Input.txt", "r", stdin);
  cin>>x>>y>>w>>h;
  int miner;
  miner = min(x,y);
  miner = min(miner,w-x);
  miner = min(miner,h-y);
  cout<<miner;
  return 0;
}