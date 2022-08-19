#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,n;
	cin>>T;
	int a[12];
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(int i=4;i<=11;i++){
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	while(T--){
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}