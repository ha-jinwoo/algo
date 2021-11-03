#include <bits/stdc++.h>
using namespace std;

void com(int n,int **c,vector<int> a){
	int i,j;
	for(i=3;i<=n;i++)
		for(j=2;j<=min(i,n)-1;j++)
			c[i][j]=c[i-1][j-1]*a[i-1]+c[i-1][j];

}

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	int i=0;
	std:: map<string,int> mymap;

	while(i!=clothes.size()){
		if(mymap.count(clothes[i][1])!=0)  mymap[clothes[i][1]]++;
		else mymap.insert ( std::pair<string,int>(clothes[i][1],1) );

		i++;
	}
	vector<int> a;
	for (std::map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		a.push_back(it->second);

	int n=a.size();
	int **c = new int *[n+1];
	for (i = 0; i < n+1; i++) c[i] = new int[n+1];
	c[n][1]=0;
	c[n][n]=1;

	for (i = 0; i < n+1; i++)c[i][0]=0;

	for(i=0;i<n;i++)
		c[n][1]+=a[i];
	for(i=0;i<n;i++)
		c[n][n]*=a[i];

	c[1][0]=a[0];
	c[1][1]=a[0];
	if(n==1)return a[0];
	i=n-1;
	while(i!=1){
		c[i][1]=c[i+1][1]-a[i];
		c[i][i]=c[i+1][i+1]/a[i];
		i--;
	}
	com(n,c,a);
	for(i=1;i<=n;i++)
		answer+=c[n][i];

	return answer;
}
int main(void){

	int i;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	int n=a.size();
	int answer=0;
	int **c = new int *[n+1];
	for (i = 0; i < n+1; i++) c[i] = new int[n+1];
	c[n][1]=0;
	c[n][n]=1;

	for (i = 0; i < n+1; i++)c[i][0]=0;

	for(i=0;i<n;i++)
		c[n][1]+=a[i];
	for(i=0;i<n;i++)
		c[n][n]*=a[i];

	c[1][0]=a[0];
	c[1][1]=a[0];
	if(n==1)return a[0];

	answer+=c[n][1];
	answer+=c[n][n];
	if(n==2)return answer;

	i=n-1;
	while(i!=1){
		c[i][1]=c[i+1][1]-a[i];
		c[i][i]=c[i+1][i+1]/a[i];
		i--;
	}
	for(i=0;i<=n;i++){
		for(int j=0;j<=min(i,n);j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	com(n,c,a);
	for(i=0;i<=n;i++){
		for(int j=0;j<=min(i,n);j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=2;i<=n-1;i++)
		answer+=c[n][i];

	cout<<answer;

	return 0;
}