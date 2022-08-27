#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long long int n;
	cin>>n;
	string s="";
	while(n!=0){
		if(n%2==0)s="0"+s;
		else s="1"+s;
		n/=2;
	}
	cout<<s;
}