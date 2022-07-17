#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int main(){//m정점수 n간선수
	int m,n;
	cin>>m>>n;
	vector<vector<int>>a;
	vector<int> b;
	for(int i=0;i<m+1;i++){
		a.push_back(b);
	}
	vector<int>indegree(m+1,0);
	int c,k;
	for(int i=0;i<n;i++)
	{cin>>c>>k;
	indegree[k]++;
	a[c].push_back(k);
	}
	queue<int> q;
	for(int i=1;i<m+1;i++)
		if(indegree[i]==0)
			q.push(i);
	int v;
	while(!q.empty()){
		v=q.front();
		cout<<v<<" ";
		q.pop();
		for(int i=0;i<a[v].size();i++){
			indegree[a[v][i]]--;
			if(indegree[a[v][i]]==0)
				q.push(a[v][i]);
		}
	}
}