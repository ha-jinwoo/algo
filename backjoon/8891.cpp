#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdio.h>
#include <numeric>
using namespace std;

int A[305][305];
int result[2][2];
void solve(int a,int b){
	for(int i=1;i<=142;i++){
			for(int j=1;A[i][j]<=a;j++){
				if(A[i][j]==a){
					if(b==0){result[0][0]=j;result[0][1]=i;}
					else{result[1][0]=j;result[1][1]=i;}
					return;
				}
			}
	}
}
int main()
{
	int x,y=1,dx,dy;
	for(int i=1;i<=300;i++){
		dy=i-1;
		y+=dy;
		x=y;
		for(int j=1;j<=300;j++){
			A[i][j]=x;
			dx=i+j;
			x+=dx;
		}
	}
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		solve(a,0);
		solve(b,1);
		cout<<A[result[0][1]+result[1][1]][result[0][0]+result[1][0]]<<endl;
	}
	return 0;
}
