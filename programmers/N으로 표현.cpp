#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = -1;

void ans(int n,int pos,int num,int number){
	if(pos>8)return;
	if (num == number){
		{
			if(answer==-1||pos<answer)
				answer=pos;
		}
		return;
	}
	int nn=0;
	for(int i=0;i<8;i++){
		nn=nn*10+n;
		ans(n,pos+i+1,num+nn,number);
		ans(n,pos+i+1,num-nn,number);
		ans(n,pos+i+1,num*nn,number);
		ans(n,pos+i+1,num/nn,number);
	}
}

int solution(int N, int number) {
	ans(N,0,0,number);
	return answer;
}

int main(){
	cout<<solution(5,12);
}