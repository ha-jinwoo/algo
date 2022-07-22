#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
string arr[25];
int v[25][25];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
vector<int> ans;
void bfs(int i,int j){
	int count=1;
	v[i][j]=1;
	queue<pair<int,int>>q;
	q.push({i,j});
	while(!q.empty()){
		int x=q.front().second;
		int y=q.front().first;
		q.pop();
		for(int k=0;k<4;k++){
			int newx=x+dx[k];
			int newy=y+dy[k];
			if(newx>=0&&newx<n&&newy>=0&&newy<n&&arr[newy][newx]=='1'&&!v[newy][newx]){
				v[newy][newx]=1;
				q.push({newy,newx});
				count++;
			}
		}
	}
	ans.push_back(count);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!v[i][j]&&arr[i][j]=='1')bfs(i,j);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;;
	for(int i:ans)cout<<i<<endl;
	return 0;
}