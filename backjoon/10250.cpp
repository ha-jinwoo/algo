#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T, h, w, n;

	cin >> T;
	while (T--) {
		cin >> h >> w >> n;
		int a, b;

		if (n % h == 0) {
			a = h;
			b = n / h;
		} else {
			b = n / h + 1;
			a = n % h;
		}

		string aa,bb,bbb;
		
		aa = to_string(a);
		bb = to_string(b);


		if (bb.size() == 1) {
			bbb = "0" + bb;
			cout << aa + bbb<<endl;

		}
		else cout << aa + bb<<endl;
	}

	return 0;
}
