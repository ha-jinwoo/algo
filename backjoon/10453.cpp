#include<stdio.h>
#include<string.h>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	int i,s,j,k,x,sum;
	cin>>n;

	for(i=0;i<n;i++){
		s=0,k=0;
		sum=0;
		string s1,s2;
		cin>>s1>>s2;
		int *arr1=new int[s1.size()];
		int *arr2=new int[s1.size()];
		for(j=0;j<s1.size();j++){
			if(s1[j]=='b')arr1[s]=j,s++;
			if(s2[j]=='b')arr2[k]=j,k++;
		}
		for(x=0;x<k;x++)sum=sum+abs(arr1[x]-arr2[x]);
			cout<<sum<<endl;

	}
	return 0;
}