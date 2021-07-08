// 친구 네트워크

#include <bits/stdc++.h>

using namespace std;

int sizes[200002];
int par[200002];

int find(int i){
    if(par[i] == i) return i;
    return par[i] = find(par[i]);
}

void Union(int x, int y) {
  int px = find(x), py = find(y);
  
  if( px != py ){
    if (sizes[px] < sizes[py]) swap(px, py);
    sizes[px] += sizes[py];
    par[py] = px;
  }
}

int main(){
  freopen("Input.txt", "r", stdin);

  int T;
  cin>>T;

  while(T--){
    string s1,s2;
    map<string, int> map;

    for (int i = 0; i < 200002; i++) {
			sizes[i] = 1;
			par[i] = i;
		}

		int n = 1, m, px, py;
    cin>>m;
    while(m--){
      cin >> s1 >> s2;

      if (map.count(s1) == 0) map[s1] = n++;		
			if (map.count(s2) == 0) map[s2] = n++;

      Union(map[s1], map[s2]);

      px = find(map[s1]);
      py = find(map[s2]);

      cout << max(sizes[px], sizes[py]) << endl;
    }
  }
}