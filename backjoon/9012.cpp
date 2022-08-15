#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	int n;
	cin>>n;
	for(int j=0;j<n;j++){
		string ss;
		cin>>ss;
		vector<char> s;
		int flag=1;
		for(int i=0;i<ss.size();i++) {
			char sss=ss[i];
			s.push_back(sss);
		}
		int count=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(')count++;
			else{
				if(count>0)count--;
				else{count--;break;}
			}
		}
		if(count==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
}