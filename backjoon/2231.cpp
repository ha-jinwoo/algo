#include<iostream>

using namespace std;


int main(){
	int a,n,i,b,c;
	cin>>n;
	for(i=1;i<=n;i++){
		a=i;
		b=i;
		while(a!=0){
			c=a%10;
			b=b+c;
			a=a/10;
		}

		if(b==n)break;

	}
	if(i==n+1)cout<<"0";
	else
	cout<<i;
	return 0;
}