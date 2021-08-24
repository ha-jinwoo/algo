//체스 다시 칠하기

#include <bits/stdc++.h>

using namespace std;

int M,N;
char board[100][100];

int main(){
  freopen("Input.txt", "r", stdin);
  int cntB = 0, cntW = 0;
  cin>>M>>N;

  for(int i = 0; i<M; i++){
    cin>>board[i];
  }
  int miner = INT_MAX;
  for(int i = 0; i<M-7; i++){
    for(int j = 0; j<N-7; j++){
      cntB = 0;
      cntW = 0;
      for(int a = i; a<i+8; a++){
        for(int b = j; b<j+8; b++){
          if((a+b) % 2 == 0){
            if(board[a][b] == 'B')
              cntW++;
            else 
              cntB++;
          }else{
            if(board[a][b] == 'B')
              cntB++;
            else
              cntW++;
          }
        }
      }
      miner = min(miner,cntB);
      miner = min(miner,cntW);
    }
  }
  cout<<miner;
  return 0;
}