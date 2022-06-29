#include<iostream>
#include <queue>

using namespace std;

int visited[1001];
int arr[1001][1001];
int n,m,v;
void dfs(int v){
	cout<<v<<" ";
	visited[v]=1;
	for(int i=1;i<=n;i++){
		if(arr[v][i]&&!visited[i]){
			dfs(i);
		}
	}
}
void bfs(int v){
	visited[v]=1;
	queue<int> q;
	q.push(v);

	while(!q.empty()){
		v = q.front();
		q.pop();
		cout << v << " ";
		for(int i=1;i<=n;i++){
			if(arr[v][i]&&!visited[i]){
				q.push(i);
				visited[i]=1;
			}
		}
	}
}

int main(){
	int a,b;
	cin>>n>>m>>v;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	dfs(v);
	for(int i=1;i<=n;i++){
		visited[i]=0;
	}
	cout<<endl;
	bfs(v);
}