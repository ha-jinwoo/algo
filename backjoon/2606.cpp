#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int c[10002];
int count=0;
vector<vector<int>> g(10002, vector<int>());

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(unsigned int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			if(!c[y]) {
				count++;
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main(void) {
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(1);
	cout<<count;
	return 0;
}