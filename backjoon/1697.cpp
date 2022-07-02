#include <cstdio>
#include <queue>
#include <utility>
#include <iostream>
#include <queue>

using namespace std;
const int maxvalue = 100000;
bool v[maxvalue + 1];

int main() {
	queue<int> q;
	bool traverse;

	int n, k, seg = 1, cnt, ans = 0;
	cin >> n >> k;
	q.push(n);

	while (!q.empty()) {
		cnt = 0;
		traverse = false;
		for (int i = 0; i < seg; i++) {
			int x = q.front();
			q.pop();
			if (x == k) {
				cout << ans;
				return 0;
			}
			v[x] = true;
			if (x + 1 <= maxvalue && !v[x + 1]) {
				q.push(x + 1);
				traverse = true;
				cnt++;
			}
			if (x - 1 >= 0 && !v[x - 1]) {
				q.push(x - 1);
				traverse = true;
				cnt++;
			}
			if (2 * x <= maxvalue && !v[2 * x]) {
				q.push(2 * x);
				traverse = true;
				cnt++;
			}
		}
		seg = cnt;
		if (traverse)
			ans++;
	}

}
