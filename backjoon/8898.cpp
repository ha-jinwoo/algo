#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MAX 1005
vector <int> adj[MAX];
int d[MAX]={};
bool v[MAX];
int S[MAX],T[MAX],w[MAX][MAX];
int dfs(int i){
    if(v[i]) return false;
    v[i]=true;
    for(int ii=0;ii < adj[i].size();ii++) {
    	int next=adj[i][ii];
    	if(!d[next] || dfs(d[next])){ d[next]=i; return true;}
    }
    return false;
}
int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
	int n;
	int total=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",S+i);
	for (int i=1;i<=n;i++) scanf("%d",T+i);
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) scanf("%d",w[i]+j), w[j][i] = w[i][j];
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (S[i]+T[i]+w[i][j] <= S[j]) adj[i].push_back(j);

	vector <int> result;
	for(int i =1;i<=n;i++){
		std::fill(v,v+MAX,false);
		if(dfs(i))total++;
		else result.push_back(i);
	}
	printf("%d\n",n-total);
	for(int i=0;i<result.size();i++)printf("%d ",result[i]);
	printf("\n");
	}
	return 0;
}