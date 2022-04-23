#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
struct h{
	int a;
	int b;
};
bool comparex(struct h h1 ,struct h h2){
	return h1.a<h2.a;
}
int solution(vector<vector<int>> routes) {
	int answer = 0;
	vector<struct h> c;
	for(int i=0;i<routes.size();i++){
		struct h t;
		t.a=routes[i][0];
		t.b=routes[i][1];
		c.push_back(t);
	}
	sort(c.begin(),c.end(),comparex);
	int i=0;
	int start=c[0].a,end=c[0].b;
	int j;
	while(i!=c.size()){
		answer++;
		j=i+1;
		start=c[i].a;
		end=c[i].b;
		while(j!=c.size()){
			if(c[j].a>end)break;
			start=c[j].a;
			if(end>c[j].b)end=c[j].b;
			j++;
		}
		i=j;
	}
	return answer;
}