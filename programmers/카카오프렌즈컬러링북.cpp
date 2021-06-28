#include <bits/stdc++.h>

using namespace std;

bool v[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int bfs(int i,int j,int m,int n, vector<vector<int>> picture){

	v[i][j]=true;

  int g = picture[i][j];

	queue<pair<int,int>> q;
	q.push(make_pair(i,j));

  int count = 1;
	while(!q.empty()){
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for(int k=0;k<4;k++){
			int newx=x+dx[k];
			int newy=y+dy[k];

			if( 0<=newx && newx<n && 0<=newy && newy<m && picture[newy][newx]==g && v[newy][newx]==false){
				v[newy][newx]=true;
				q.push(make_pair(newy,newx));
        count++;
			}
		}
	}
  return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
  int number_of_area = 0;
  int max_size_of_one_area = 0;  
  for(int i = 0 ; i <m;i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            v[i][j] = false;
        }
    }
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      if(v[i][j]==false && picture[i][j] != 0){
        int Size = bfs(i, j, m, n, picture);
        if(Size > max_size_of_one_area) max_size_of_one_area = Size;
        number_of_area++;
      } 
    }
  }
  vector<int> answer(2);
  answer[0] = number_of_area;
  answer[1] = max_size_of_one_area;
  return answer;
}

int main(){
  vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
  vector<int> answer = solution(6,4,picture);
  cout<<answer[0]<<" "<<answer[1];
	return 0;
}
