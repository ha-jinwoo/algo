// 사이클 게임

#include <bits/stdc++.h>

using namespace std;

int n, m, ans, par[1000001];

int find(int i){
    if(par[i] == i) return i;
    return par[i] = find(par[i]);
}

int main(){
    freopen("Input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        int px = find(x), py = find(y);
        cout<<"px = "<<px<<"py = "<<py<<endl;
        if(px == py){
          if(!ans)
            ans = i + 1;    
        }
        par[px] = py;
    }
    printf("%d", ans);
}