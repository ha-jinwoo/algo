#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;



void bfs(int start,queue <int> q,vector<vector<int>>g,vector <bool> v,vector <int>&count){

	q.push(start);
	v[start]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();

		for(int i=0; i<g[x].size();i++){
			int y=g[x][i];
			if(!v[y]){
				q.push(g[x][i]);
				v[y]=1;
				count[g[x][i]]=count[x]+1;
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<int>count(n+1,0);
	queue <int> q;
	vector <bool> v(n+1,0);
	vector <int> b;
	vector<vector<int>> g;
	for(int i=0;i<n+1;i++)g.push_back(b);
	for(int i=0;i<edge.size();i++)
    {g[edge[i][0]].push_back(edge[i][1]);
   g[edge[i][1]].push_back(edge[i][0]);
    }
	bfs(1,q,g,v,count);
	int max=0;
	for(int i=1;i<=n;i++)
		if(max<count[i])max=count[i];
	for(int i=1;i<=n;i++)if(count[i]==max)answer++;
	return answer;
}