#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("Input.txt", "r", stdin);
	int n, m, k; 
  cin >> n >> m >> k;

	vector <vector<pair<int,int>>> adj(n + 1);
  
	for(int i=1;i<=m;i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[b].push_back({w, a});
	}

	priority_queue <pair<long long,long long>> q;
	vector <long long> dist(n + 1, 1e18);
  int x; 

	for(int i=1;i<=k;i++) {
    cin >> x;
		q.push({0, x});
		dist[x] = 0;
	}

	while (q.size()) {
		pair<long long,long long> now = q.top(); 
    q.pop();
		now.first = -now.first;
		if (dist[now.second] < now.first) continue;
		for (pair<int,int> next : adj[now.second]) {
			if (dist[next.second] <= dist[now.second] + next.first) continue;
			dist[next.second] = dist[now.second] + next.first;
			q.push({-dist[next.second], next.second}); 
		}
	}

	pair<long long,long long> ans = { 0, 1e18 };
	for (int i = 1; i <= n; i++) // 최댓값 구하기
		if (dist[i] > ans.first) ans = { dist[i], i };
	cout << ans.second << '\n' << ans.first << '\n';
	return 0;
}