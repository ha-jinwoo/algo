#include <iostream>
#include <vector>
using namespace std;

int check(vector<int> a){
	int k=a[0];
	for(int i=1;i<a.size();i++){
		if(a[i]!=k)return 0;
	}
	return 1;
}
int main() {
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int n;
		cin>>n;
		int count=0;
		vector<int> a;
		for(int j=0;j<n;j++){
			int k;
			cin>>k;
			a.push_back(k);
		}
			while(1){
			for(int y=0;y<a.size();y++){
				if(a[y]%2==1)a[y]++;
			}
			if(check(a)) {cout<<count<<endl;break;}
			vector<int >b(n);
			for(int y=0;y<a.size();y++){
				b[y]=a[y];
				a[y]/=2;
			}
			for(int y=0;y<a.size()-1;y++){
				a[y+1]=(b[y]/2)+a[y+1];
			}
			a[0]=(b[a.size()-1]/2)+a[0];
			count++;
			}

	}
	return 0;
}