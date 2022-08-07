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
char a[11][33];
int v[11];
int main()
{	int T;
	int r,s,p;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s", a + i);
			v[i]=1;
		}
	for(int i=0;a[0][i];i++){
		r=s=p=0;
		for(int j=0;j<n;j++)if(v[j]){
			if(a[j][i]=='R')r++;
			if(a[j][i]=='S')s++;
			if(a[j][i]=='P')p++;
		}
	if(!r && s) for(int j=0;j<n;j++) if(a[j][i]=='P')v[j]=0;
	if(!s && p) for(int j=0;j<n;j++) if(a[j][i]=='R')v[j]=0;
	if(!p && r) for(int j=0;j<n;j++) if(a[j][i]=='S')v[j]=0;
	}
	int count=0,result;
	for(int i=0;i<n;i++) if(v[i]) {count++; result=i+1;}
	if(count==1)printf("%d\n",result);
	else printf("0\n");
	}
	return 0;
}
