#include <iostream>
using namespace std;

int max1(int arr[],int c){
	int i;
	int max;
	max=c-1;
	if(c>=1){

		for(i=c-1;i>=0;i--){
			if(arr[i]>=arr[max])max=i;

		}

	}
	return max;

}
void next(int arr[],int c,int j){
	int k,i;
	while(j!=c-1){
		k=arr[j+1];
		arr[j]=k;
		j++;}
	arr[c-1]=0;
}
void next2(int arr[],int c,int j){
	int k,i,a;
	a=arr[j];
	while(j!=c-1){
		k=arr[j+1];
		arr[j]=k;
		j++;}
	arr[c-1]=a;
}
int main()
{
	int kx,jx,i,n,m,max,c;
	long long int count=0;
	cin>>kx;
	for(jx=0;jx<kx;jx++){
		cin>>n>>m;

		int *arr=new int[n];
		for(i=0;i<n;i++)cin>>arr[i];

		c=n;

			while(1){
				max=max1(arr,c);
				if(max==0&&m==0){
					count++;
					break;
				}
				else if(max==0){
					m--;
					next(arr,c,max);
					count++;
					c--;}
				else{
					if(m==0)m=c-1;
					else m--;
					next2(arr,c,0);
				}
			}

			cout<<count<<endl;

		count=0;
	}
	return 0;
}