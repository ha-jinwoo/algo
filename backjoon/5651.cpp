#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MAX 305


struct h{
	int from;
	int to;
};
int main(){

	int T;
	scanf("%d",&T);
	while(T--){
	int S=1,E;
	int c[MAX][MAX]={}, f[MAX][MAX]={},total=0;
	vector<int> adj[MAX];
	int n,m;
	scanf("%d %d", &n,&m);
	vector<h> EDGE;
	for(int i=1;i<=m;i++){
		int from,to,val;
		scanf("%d %d %d", &from, &to, &val);
		adj[from].push_back(to);
		adj[to].push_back(from);

		c[from][to]+=val;
		struct h h;
		h.from = from;
		h.to = to;
		EDGE.push_back(h);
	}

	E=n;

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
	int ans = 0;
	for(int i=0;i<EDGE.size();i++){
					S=EDGE[i].from;
					E=EDGE[i].to;
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
					if(prev[E]==-1) ans++;
	}
	printf("%d\n",ans);
	}
	return 0;
}