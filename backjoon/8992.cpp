#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 405
#define SERO 200
int S=MAX-2,E=MAX-1;
struct h{
	int x;
	int y;
	int xx;
	int yy;
	int w;
};
int main(){
	int T;
	cin>>T;
	while(T--){
	int c[MAX][MAX]={}, f[MAX][MAX]={},d[MAX][MAX]={},total=0;
	vector<int> adj[MAX];
	int n,m;
	cin>>n>>m;
	vector <h> garo;
	struct h h;
	garo.push_back(h);
	for(int i=1;i<=n;i++){
		adj[S].push_back(i), adj[i].push_back(S),c[S][i]=1;
	}
	for(int i =1; i <=m;i++) {
			adj[E].push_back(SERO+i), adj[SERO+i].push_back(E),c[SERO+i][E]=1;
	}
	for(int i=1;i<=n;i++){
		int x,y,xx,yy,w;
		cin>>x>>y>>xx>>yy>>w;
		struct h h;
		if(x>xx)swap(x,xx);
		h.x=x,h.y=y,h.xx=xx,h.yy=yy,h.w=w;
		garo.push_back(h);
	}
	for(int i=1;i<=m;i++){
		int x,y,xx,yy,w;
		cin>>x>>y>>xx>>yy>>w;
		if(y>yy)swap(y,yy);
		for(int j=1;j<=garo.size()-1;j++){
			if(garo[j].x<=x && x<=garo[j].xx)
				if(y<=garo[j].y && garo[j].y<=yy){
					c[j][SERO+i]=1;
					d[j][SERO+i]=-garo[j].w *w;
					d[SERO+i][j]=garo[j].w *w;
					adj[j].push_back(SERO+i);
					adj[SERO+i].push_back(j);
				}
		}
	}
	int cnt=0;
	while(1){
				int prev[MAX],dist[MAX];
				bool inQ[MAX]={};
				std::fill(prev,prev+MAX,-1);
				std::fill(dist,dist+MAX,1e9);
				std::queue<int> Q;
				Q.push(S);
				inQ[S]=true;
				dist[S]=0;

				while(!Q.empty()){
					int cur = Q.front();
					Q.pop();
					inQ[cur] = false;

					for(int next:adj[cur]){
						if(c[cur][next] - f[cur][next] >0 && dist[next] > dist[cur]+d[cur][next]){
							dist[next] = dist[cur]+d[cur][next];
							prev[next] = cur;
							if(!inQ[next]) inQ[next] = true, Q.push(next);
						}
					}
				}
				if(prev[E]==-1) break;
				int flow = 1e9;

				        for (int i = E; i != S; i = prev[i])
				            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

				        for (int i = E; i != S; i = prev[i])
				        {
				            total += flow * d[prev[i]][i];
				            f[prev[i]][i] += flow;
				            f[i][prev[i]] -= flow;
				        }

				        cnt+=flow;
	}
	printf("%d %d\n",cnt,-total);
	}
	return 0;
}