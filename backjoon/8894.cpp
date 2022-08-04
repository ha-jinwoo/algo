#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace::std;
 
vector<int> v;
int edge_num;
bool edge[11][11];
int edge_chk[11][11];
bool is_ans;
bool chk[11];
int mid_point[11][11];
vector<PII> decomp[11][11];
 
void get_midpoint(){
    mid_point[1][3] = 2;
    mid_point[1][7] = 4;
    mid_point[1][9] = 5;
    mid_point[2][8] = 5;
    mid_point[3][7] = 5;
    mid_point[3][9] = 6;
    mid_point[4][6] = 5;
    mid_point[7][9] = 8;
}
 
void get_decomp(){
    for(int i=1; i<=9; i++){
        for(int j=i+1; j<=9; j++){
            if(mid_point[i][j]==0){
                decomp[i][j].push_back(PII(i,j));
                continue;
            }
            decomp[i][j].push_back(PII(i,mid_point[i][j]));
            decomp[i][j].push_back(PII(mid_point[i][j],j));
        }
    }
}
 
void process(){
    if(is_ans) return;
    if(edge_num==0 && v.size()>=4){
        for(auto p: v)
            printf("%d ",p);
        printf("\n");
        is_ans = true;
    }
    for(int i=1; i<=9; i++){
        if(v.size()==0){
            chk[i]=true;
            v.push_back(i);
            process();
            chk[i]=false;
            v.pop_back();
        }
        
        if(chk[i]) continue;
        bool con = false;
        int p1 = v.back(), p2 = i;
        if(p1>p2) swap(p1, p2);
        if(!chk[mid_point[p1][p2]]) continue;
        for(auto p: decomp[p1][p2])
            if(!edge[p.first][p.second])
                con = true;
        if(con) continue;
        
        chk[i] = true;
        v.push_back(i);
        for(auto p: decomp[p1][p2]){
            edge_chk[p.first][p.second]++;
            if(edge_chk[p.first][p.second]==1)
                edge_num--;
        }
        
        process();
        
        chk[i] = false;
        v.pop_back();
        for(auto p: decomp[p1][p2]){
            edge_chk[p.first][p.second]--;
            if(edge_chk[p.first][p.second]==0)
                edge_num++;
        }
    }
}
 
void solve(){
    edge_num=0;
    is_ans = false;
    v.clear();
    chk[0] = true;
    for(int i=1; i<=9; i++) chk[i] = false;
    for(int i=1; i<=9; i++) for(int j=1; j<=9; j++)
        edge[i][j] = false, edge_chk[i][j] = 0;
        
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int v1, v2;
        scanf("%d %d",&v1,&v2);
        if(v1>v2) swap(v1,v2);
        if(v1==v2) continue;
        for(auto p: decomp[v1][v2])
            edge[p.first][p.second] = true;
    }
    
    for(int i=1; i<=9; i++) for(int j=1; j<=9; j++)
        if(edge[i][j])
            edge_num++;
            
    process();
    
    if(!is_ans)
        printf("IMPOSSIBLE\n");
}
 
int main(){
    get_midpoint();
    get_decomp();
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}