#include <bits/stdc++.h>
using namespace::std;
 
int n, l, r;
long long dp[25][25][25]; // 정답 = dp[n][l][r]
 
void get_dp(){
    dp[1][1][1] = 1;
    for(int i=2; i<=20; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=i; k++){
                dp[i][j][k] = dp[i-1][j-1][k]+dp[i-1][j][k-1]+(i-2)*dp[i-1][j][k];
            }
        }
    }
}
 
void solve(){
    scanf("%d %d %d",&n,&l,&r);
    printf("%lld\n",dp[n][l][r]);
}
 
int main(){
    get_dp();
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}