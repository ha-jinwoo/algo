#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int n, m, k;
int arr[50][50];
int v[50][50];
void dfs(int y, int x) {
	if (v[y][x])return;
	v[y][x]++;
	for (int i = 0; i < 4; i++) {
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||ny>=n||nx<0||nx>=m)continue;
		if(arr[ny][nx]&&!v[ny][nx]){
			dfs(ny,nx);
		}
	}
}
int main(void) {
	int T, x, y;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		cin >> m >> n >> k;
		for(int i=0;i<50;i++)for(int j=0;j<50;j++)arr[i][j]=0;
		for(int i=0;i<50;i++)for(int j=0;j<50;j++)v[i][j]=0;
		int ans = 0;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !v[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}