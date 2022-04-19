#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0,n,h=0;
	sort(citations.begin(),citations.end());
	std::vector<int>::iterator x;
	while(h!=1001){
		x=lower_bound(citations.begin(),citations.end(),h);
		n=citations.end()-x;
		if(h<=n){
			answer=h;
			break;
		}
		h++;
	}
	return answer;
}
int main(){

	return 0;
}