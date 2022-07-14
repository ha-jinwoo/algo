#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MAX 201
std::vector<int> adj[MAX];
int d[MAX]={};
bool v[MAX];

int dfs(int i){
    if(v[i]) return false;
    v[i]=true;
    for(int next: adj[i]) if(!d[next] || dfs(d[next])){ d[next]=i; return true;}
    return false;
}

int main(){

	int n,m;
	int k,u,total=0;
	scanf("%d %d",&n,&m);
	for(int i =1; i <=n ;i++){
	        scanf("%d",&k);
	        while(k--) scanf("%d",&u), adj[i].push_back(u);
	}
	for(int i =1;i<=n;i++){
		std::fill(v,v+200,false);
		if(dfs(i))total++;
	}

	printf("%d\n",total);
	return 0;
}