#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int i=1,j=1,k;
	vector<vector<long long>> a;
	vector<long long> b(m);

	for(i=0;i<n;i++)a.push_back(b);
	for(i=0;i<m;i++)a[0][i]=1;
	for(i=0;i<n;i++)a[i][0]=1;
	for(i=0;i<puddles.size();i++){ //웅덩이가 있으면 못감
		a[puddles[i][1]-1][puddles[i][0]-1]=-1;
		if(puddles[i][1]-1==0){
			k=puddles[i][0]-1;
			while(k!=m){
				a[0][k]=0;
                k++;
			}	
		}
		if(puddles[i][0]-1==0){
			k=puddles[i][1]-1;
			while(k!=n){
				a[k][0]=0;
                k++;
			}
		}
	}
	a[0][0]=0;
	i=1;j=1;
	while(i!=n){
		j=1;
		while(j!=m){
			if(a[i][j]==-1)a[i][j]=0;	
			else a[i][j]=(a[i-1][j]+a[i][j-1])%1000000007;
			j++;
		}
		i++;
	}

	return answer=a[n-1][m-1]%1000000007;
}