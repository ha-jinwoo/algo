#include <bits/stdc++.h>
using namespace::std;
 
const int N = 105;
const long long INF = -((long long)1<<60);
 
int n,m;
int s1,s2,s3,t1,t2,t3;
long long edge[3][N][N];
long long dp[N][N][N];
 
void input(){
    scanf("%d %d",&n, &m);
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) for(int k=0; k<3; k++) edge[k][i][j] = INF;
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) for(int k=0; k<=n; k++) dp[i][j][k] = INF;
    scanf("%d %d %d %d %d %d",&s1,&s2,&s3,&t1,&t2,&t3);
    for(int i=1; i<=m; i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edge[0][u][v] = edge[1][u][v] = edge[2][u][v] = w;
    }
    edge[0][0][s1]=edge[1][0][s2]=edge[2][0][s3]=0;
}
 
void solve(){
    dp[0][0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++) for(int k=0; k<i; k++) for(int l=0; l<i; l++){
            dp[i][k][l] = max(dp[i][k][l], dp[j][k][l]+edge[0][j][i]);
            dp[j][i][l] = max(dp[j][i][l], dp[j][k][l]+edge[1][k][i]);
            dp[j][k][i] = max(dp[j][k][i], dp[j][k][l]+edge[2][l][i]);
        }
    }
    printf("%lld\n",dp[t1][t2][t3]<0?0:dp[t1][t2][t3]);
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        input();
        solve();
    }
    return 0;
}