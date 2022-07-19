#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MAX 805
#define CITY 400
int S=1,E=402;

int main(){

	int c[MAX][MAX]={}, f[MAX][MAX]={},total=0;
	vector<int> adj[MAX];
	int n,m;
	scanf("%d %d", &n, &m);
	adj[1].push_back(401),adj[401].push_back(1),c[1][401]=1e9;
	adj[2].push_back(402),adj[402].push_back(2),c[2][402]=1e9;
	for(int i=3;i<=n;i++){
		adj[i].push_back(CITY+i),adj[CITY+i].push_back(i),c[i][CITY+i]=1;
	}
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
			adj[CITY+u].push_back(v),adj[v].push_back(CITY+u),c[CITY+u][v]=1;
			adj[u].push_back(CITY+v),adj[CITY+v].push_back(u),c[CITY+v][u]=1;
	}

	while(1){
				int prev[MAX];
				std::fill(prev,prev+MAX,-1);
				std::queue<int> Q;
				Q.push(S);

				while(!Q.empty()){
					int cur = Q.front();
					Q.pop();

					for(int next:adj[cur]){
						if(prev[next]==-1 && c[cur][next] - f[cur][next] >0  ){
							Q.push(next);
							prev[next] = cur;
							if(next==E)
								break;
						}
					}
				}
				if(prev[E]==-1) break;
				int flow = 1e9;

				        for (int i = E; i != S; i = prev[i])
				            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

				        for (int i = E; i != S; i = prev[i])
				        {

				            f[prev[i]][i] += flow;
				            f[i][prev[i]] -= flow;
				        }
				        total += flow;
	}
	printf("%d\n",total);
	return 0;
}
