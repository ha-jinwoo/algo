#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> x;
			g[i].push_back(x);
		}
	}
	int dp[n][n];
	dp[0][0] = g[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + g[i][0];
		dp[i][i] = dp[i - 1][i - 1] + g[i][i];
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1] + g[i][j], dp[i - 1][j] + g[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans;
	return 0;
}