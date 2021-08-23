// 체스판 다시 칠하기

#include <bits/stdc++.h>

using namespace std;

int M,N;
char arr[100][100];

int solution(int X, int Y, char S){
  int count = 0;
  for(int i = X; i<X+8; i++){
    for(int j = Y; j<Y+8; j++){
      if(arr[i][j] == 'B' && S=='B'){
        S = 'W'; 
      }
      else if(arr[i][j] == 'W' && S == 'W'){
        S='B';
      }
      else{
        if(S== 'W') S= 'B';
        else S = 'W';
        count++;
      } 
    }
    if(S== 'W') S= 'B';
    else S = 'W';
  }
  return count;
}

int main(){
  freopen("Input.txt", "r", stdin);
  cin>>M>>N;
  for(int i = 0; i<M; i++){
    cin>>arr[i];
  }
  int result = INT_MAX;
  for(int i = 0; i<=M-8; i++){
    for(int j = 0; j<=N-8; j++){
      result = min(result, solution(i,j,'B'));
      result = min(result, solution(i,j,'W'));
    }
  }
  cout<<result;
  return 0;
}