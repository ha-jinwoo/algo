#include <string>
#include <vector>

using namespace std;
int arr[201][201];
int visited[201];
void dfs(vector<vector<int>> computers,int v,int n){
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(computers[v][i]&&!visited[i])dfs(computers,i,n);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(computers,i,n);
            answer++;
        }
    }
    return answer;
}