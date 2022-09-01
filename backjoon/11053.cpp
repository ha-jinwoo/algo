#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{int n,i,size=1,max=1;
	scanf("%d",&n);
	int *k=new int[n+1];
	int *c=new int[n+1];
	int *length=new int[n+1];
for( i=1;i<=n;i++)scanf("%d",&k[i]);
c[1]=k[1];
length[1]=1;
for( i=2;i<=n;i++){

	if(k[i]<c[1]){
		c[1]=k[i];
		length[i]=1;
	}

	else if(k[i]>c[size]){

		c[++size]=k[i];
		length[i]=size;
	}

	else{//int*lower_bound(int *start,int *end,int found)함수는 found보다 큰 첫번째 요소의 위치를 가리키는
		//포인터를 반환합니다.
		int *p=std::lower_bound(c+1,c+size+1,k[i]);
		*p=k[i];
		length[i]=p-c;//길이=lower_bound의 반환값-배열이름(첫번째 요소)
	}

}
for(i=2;i<n+1;i++){
	if(length[max]<length[i])max=i;
}
printf("%d ",length[max]);
return 0;
}
