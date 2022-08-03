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
void solve(string a[],int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(i==j)continue;
			string b=a[i]+a[j];
			string c=b;
			reverse(c.begin(),c.end());
			if(c==b){cout<<c<<endl;return;}
		}
	}
	cout<<"0"<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		string a[100];
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>a[i];
		}
		solve(a,k);
	}
	return 0;
}