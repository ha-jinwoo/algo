#include <bits/stdc++.h>

using namespace std;

int solution(int length, int weight, vector<int> truckweight) {
	int n=length;
	int *b=new int[n];

	int totalweight=0;
	int answer = 0,i=0,k;
	for(k=0;k<length;k++)b[k]=0;
	do{

		if(b[n-1]!=0)totalweight-=b[n-1];
		for(k=n-2;k>0;k--) b[k+1]=b[k];
		b[1]=b[0];

		if(i<truckweight.size()){
			if(totalweight+truckweight[i]<=weight){

				b[0]=truckweight[i];
				totalweight+=b[0];
				i++;
			}
			else b[0]=0;
		}
		else b[0]=0;
		answer++;
	}
	while(totalweight!=0);
	return answer;
}