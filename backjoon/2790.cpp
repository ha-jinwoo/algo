//F7
#include <bits/stdc++.h>

using namespace std;

int main(){
  int N,score;
  cin>>N;

  vector <int> scores;
  for(int i = 0; i<N; i++){
    cin>>score;
    scores.push_back(score);
  }

  sort(scores.begin(),scores.end(),greater<int>());
  
  int count = 1;
  score = scores[0]+1;
  for(int i = 1; i<N; i++) {
    if(score <= scores[i] + N) count++;
    score = max(score,scores[i]+i+1);
  }
  cout<<count;
  return 0;
}