#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> count(1000001);
	count[0]=0;
	count[1]=0;
	for(int i=2;i<=n;i++){
		count[i]=count[i-1]+1;
		if(i%3==0&&count[i]>count[i/3]+1)count[i]=count[i/3]+1;
		if(i%2==0&&count[i]>count[i/2]+1)count[i]=count[i/2]+1;
	}
	cout<<count[n];
	return 0;
}