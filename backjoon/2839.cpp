#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	int count=0;
	while(1){
		if(n%5==0){
			cout<<n/5+count;
			return 0;
		}
		count++;
		n-=3;
		if(n<0){
			cout<<"-1";
			return 0;
		}
	}
	return 0;
}