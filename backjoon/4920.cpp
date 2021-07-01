//테트리스

#include <bits/stdc++.h>

using namespace std;

int dx[13][4] = {{0,1,2,3}, {0,0,0,0}, {0,1,1,2}, {0,0,-1,-1}, {0,1,2,2}, {0,0,0,-1}, {0,0,1,2}, {0,1,0,0}, {0,1,1,1}, {0,-1,0,1}, {0,0,0,1}, {0,-1,1,0}, {0,1,0,1}}; 
int dy[13][4] = {{0,0,0,0}, {0,-1,-2,-3}, {0,0,-1,-1}, {0,-1,-1,-2}, {0,0,0,-1}, {0,-1,-2,-2}, {0,-1,-1,-1}, {0,0,-1,-2}, {0,1,0,-1}, {0,-1,-1,-1}, {0,-1,-2,-1}, {0,0,0,-1}, {0,0,-1,-1}};

int main(){
  // freopen("Input.txt", "r", stdin);
  int N,score,nx,ny;
  vector<int> result;
  while(1){
    cin>>N;
    if(N == 0)break;
    vector<vector<int>> scores(N,vector<int>(N));
    for(int i =0;i<N;i++){
      for(int j =0;j<N;j++){
        cin>>scores[i][j];
      }
    }
    score = INT_MIN;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        for(int y=0;y<13;y++){
          bool flag = true;
          int temp=0;
          for(int k=0;k<4;k++){
            nx = i+dx[y][k];
            ny = j+dy[y][k];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
              temp+=scores[nx][ny];
            }
            else{
              flag = false;
              break;
            }
          }
          if(flag) score = max(score,temp);
        }
      }
    }
    result.push_back(score);
  }
  for(int i = 0; i<result.size(); i++){
    cout<<i+1<<". "<<result[i]<<endl;
  }
  return 0;
}