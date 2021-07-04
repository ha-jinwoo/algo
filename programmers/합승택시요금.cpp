#include <bits/stdc++.h>

using namespace std;

int dist[201][3];
vector <vector<pair<int,int>>> adj(201);

void dijkstra(int start, int flag){
  priority_queue <pair<int,int>> q;

  q.push({0, start});
	dist[start][flag] = 0;

  while (q.size()) {
		pair<int,int> now = q.top(); 
    q.pop();
		now.first = -now.first;
		if (dist[now.second][flag] < now.first) continue;
		for (pair<int,int> next : adj[now.second]) {
			if (dist[next.second][flag] <= dist[now.second][flag]+ next.first) continue;
			dist[next.second][flag] = dist[now.second][flag] + next.first;
			q.push({-dist[next.second][flag], next.second}); 
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  int answer = INT_MAX;
  
  for(vector<int> fare : fares){
    adj[fare[0]].push_back({fare[2], fare[1]});
    adj[fare[1]].push_back({fare[2], fare[0]});
  }

  for(int i = 1; i<=n; i++){
    for(int j = 0; j<3; j++){
      dist[i][j] = INT_MAX;
    }
  }

  dijkstra(s,0);
  dijkstra(a,1);
  dijkstra(b,2);

  for(int i = 1; i<=n; i++){
    if(dist[i][0] == INT_MAX || dist[i][1] == INT_MAX || dist[i][2] == INT_MAX ) continue;
    answer = min(answer,dist[i][0]+dist[i][1]+dist[i][2]);
  }
  
  return answer;
}

int main() {
  vector<vector<int>> fares = {
    {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, 
    {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, 
    {1, 6, 25}
  };
  int n = 6, s = 4, a = 6, b = 2;

  cout<<solution(n,s,a,b,fares);

	return 0;
}