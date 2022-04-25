#include <bits/stdc++.h>

using namespace std;
void bfs(int s,vector<int> &v,vector <int> &ans,vector<vector<int>> g){
    v[s]=1;
    queue<int> q;
    q.push(s);
    ans[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<"x= "<<x<<" ";
        for(int i=0;i<g[x].size();i++){
            if(!v[g[x][i]]){
                cout<<g[x][i];
                q.push(g[x][i]);
                v[g[x][i]]=1;
                ans[g[x][i]]=ans[x]+1;
            }
        }
        cout<<endl;
    }
}
bool connect(string a,string b){
    int count=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i])count++;
    }
    if(count>=a.size()-1)return true;
    return false;
}
int solution(string begin, string target, vector<string> words) {
    
    words.insert(words.begin(),begin);
    vector<vector<int>> g(words.size(),vector<int>());
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words.size();j++){
            if(connect(words[i],words[j])){
        g[i].push_back(j);
        g[j].push_back(i);
    }
        }
    }
    vector<int>v(words.size());
    vector<int>ans(words.size());

    for(int i=0;i<words.size();i++){
        v[i]=0;
        ans[i]=0;
    }
    bfs(0,v,ans,g);
    
    for(int i=0;i<words.size();i++){
        if(target==words[i]){
            return ans[i];
        }
    }
    return 0;
}