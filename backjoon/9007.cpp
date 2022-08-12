#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int solution(int a,int b,int c,int k){
	a-=k;
	b-=k;
	c-=k;
	int min;
	if(abs(a)==abs(b)){
		if(a<b)min=a;
		else min=b;
	}
	else{
		if(abs(a)<abs(b))min=a;
		else min=b;
	}
	if(abs(min)==abs(c)){
		if(min>c)min=c;
	}
	else{
		if(abs(min)>abs(c))min=c;
	}
	min+=k;
	return min;
}
int main() {
	int m;
	cin>>m;
	for(int y=0;y<m;y++){
		int n,k;
		cin>>k>>n;
		vector<int> a;
		vector<int> b;
		vector<int> c;
		vector<int> d;

		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			a.push_back(k);
		}
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			b.push_back(k);
		}
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			c.push_back(k);
		}
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			d.push_back(k);
		}
		vector<int> ab;
		vector<int> cd;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int sum=a[i]+b[j];
				ab.push_back(sum);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int sum=c[i]+d[j];
				cd.push_back(sum);
			}
		}
		sort(ab.begin(),ab.end());
		sort(cd.begin(),cd.end());
		std::vector<int>::iterator low,up;

		int min=210000000;
		for(int i=0;i<ab.size();i++){
			if(k-ab[i]<=cd[cd.size()-1]){
				low=std::lower_bound (cd.begin(), cd.end(), k-ab[i]);
				up= std::upper_bound (cd.begin(), cd.end(), k-ab[i]);
				int a1,a2;

				a1=cd[(low-cd.begin())]+ab[i];
				if(a1!=k&&low-cd.begin()>0)a1=cd[(low-cd.begin())-1]+ab[i];
				a2=cd[up-cd.begin()]+ab[i];


				min=solution(a1,a2,min,k);
				if(min==k)break;}
			else{
				int min2=ab[i]+cd[cd.size()-1]-k;
				min-=k;
				if(abs(min)==abs(min2)){
					if(min>min2)min=min2;
				}
				else{
					if(abs(min)>abs(min2))min=min2;
				}
				min+=k;
			}
		}
		if(min==210000000)cout<<"0"<<endl;
		else cout<<min<<endl;
	}
}