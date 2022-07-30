#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MAX 52

int S=0,E=25;

int main(){

	int c[MAX][MAX]={}, f[MAX][MAX]={},d[MAX][MAX]={},total=0;
	vector<int> adj[MAX];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char chfrom, chto;
		int val;

		scanf(" %c %c %d", &chfrom, &chto, &val);
		int from, to;
		if('A'<=chfrom && chfrom <= 'Z')
			from = chfrom -'A';
		else
			from = chfrom - 'a' +26;

		if('A'<= chto && chto <='Z')
			to = chto -'A';
		else
			to = chto -'a' +26;
		c[from][to] += val;
		c[to][from] += val;
		adj[from].push_back(to);
		adj[to].push_back(from);
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