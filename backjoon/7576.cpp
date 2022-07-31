#include <bits/stdc++.h>
using namespace std;

int main() {
	int dx[4]={0,1,0,-1};
	int dy[4]={-1,0,1,0};
	int n,m,seg=0,cnt=0,answer=0;
	bool traverse;
	queue<pair<int,int>> q;
    cin>>m>>n;
    int arr[n][m];
    bool v[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>arr[i][j];
    		v[i][j]=false;
    		if(arr[i][j]==1){
    			q.push(make_pair(i,j));
    			seg++;
    		}
    	}
    }

    while(!q.empty()){
    	cnt=0;
    	traverse=false;
    	for(int i=0;i<seg;i++){
    	    	int x=q.front().second;
    	    	int y=q.front().first;
    	    	q.pop();
    	    	v[y][x]=1;
    	    	for(int k=0;k<4;k++){
    	    		int newx=x+dx[k];
    	    		int newy=y+dy[k];
    	    		if(newy>=0 && newy <n &&newx>=0&& newx<m && arr[newy][newx]==0 &&!v[newy][newx]){
    	    			q.push(make_pair(newy,newx));
    	    			arr[newy][newx]=1;
    	    			traverse=true;
    	    			cnt++;
    	    		}
    	    	}
    	}
    	seg=cnt;
    	if(traverse) answer++;

    }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!v[i][j] && arr[i][j] == 0) {
                    cout<<"-1"<<endl;
                    return 0;
                }
            }
        }
    cout<<answer;
    return 0;
}
