using namespace::std;
 
string s;
 
void solve(){
    cin>>s;
    s.push_back(s[0]);
    s.push_back(s[1]);
    int ppdir=0, pdir=0, dir=0; // 0 = 위, 1 = 왼, 2 = 아래, 3 = 오른
    int x=1, y=1; // 단조 = 1, 단조X = 0
    for(int i=0; i<s.size(); i++){
        if(s[i]=='L'){
            ppdir=pdir;
            pdir=dir;
            dir=(dir+1)%4;
        }
        else{
            ppdir=pdir;
            pdir=dir;
            dir=(dir+3)%4;
        }
        if(i<=1) continue;
        if(ppdir==1 && pdir==0 && dir==3) y=0;
        if(ppdir==3 && pdir==2 && dir==1) y=0;
        if(ppdir==0 && pdir==3 && dir==2) x=0;
        if(ppdir==2 && pdir==1 && dir==0) x=0;
    }
    printf("%d\n",x+y);
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}