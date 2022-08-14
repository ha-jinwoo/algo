#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> fibo(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	int i=2;
	while(1){
		int k=a[i-1]+a[i-2];
		if(k>1000000000)break;
		else a.push_back(k);
		i++;
	}
	return a;

}



int main() {
	vector <int> a=fibo();
	int m;
	cin>>m;
	for(int j=0;j<m;j++){
		int n;
		cin>>n;
		int i=0;
		for(i=0;i<a.size();i++)if(a[i]>n)break;
		i--;
		vector<int>b;
		while(1){
			b.push_back(a[i]);
			n=n-a[i];
			if(n==0)break;
			i=0;
			for(i=0;i<a.size();i++)if(a[i]>n)break;
			i--;
		}
		for(int y=b.size()-1;y>=0;y--) cout<<b[y]<<" ";
		cout<<endl;
	}
	return 0;
}
