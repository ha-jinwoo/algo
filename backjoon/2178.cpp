#include <bits/stdc++.h>
using namespace std;

int check[100][100];
string arr[100];
bool v[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int n,m;
void bfs(int i,int j){
	v[i][j]=true;
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for(int k=0;k<4;k++){
			int newx=x+dx[k];
			int newy=y+dy[k];
			if(newx>=0&&newx<m&&newy>=0&&newy<n&&arr[newy][newx] == '1' &&!v[newy][newx]){
				check[newy][newx]=check[y][x]+1;
				v[newy][newx]=1;
				q.push(make_pair(newy,newx));
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>arr[i];
	bfs(0,0);
	cout<<check[n-1][m-1]+1;
	return 0;
}
