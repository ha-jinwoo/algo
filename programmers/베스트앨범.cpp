#include <bits/stdc++.h>

using namespace std;

struct h
{
	string x;
	int y;
	int z;
};
bool comparex(struct h &a,struct h &b){
	return a.x<b.x;
}
bool comparey(const struct h &a,const struct h &b){
	return a.y>b.y;
}

vector<int> index(vector<struct h> h,vector<struct h> h1,int i){
	vector<int> a;
	int j=0;
	while(1){
		if(h[j].x==h1[i].x){
			a.push_back(j);
			while(h[j].x==h1[i].x) j++;
			a.push_back(j-1);
			break;
		}
		j++;
	}
	return a;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	std:: map<string,int> mymap;
	vector<struct h> h;
	int i=0;
	while(i!=genres.size()){
		struct h h2;
		h2.x=genres[i];
		h2.y=plays[i];
		h2.z=i;
		h.push_back(h2);
		if(mymap.count(genres[i])!=0) mymap[genres[i]]+=plays[i];
		else mymap.insert ( std::pair<string,int>(genres[i],plays[i]) );
		i++;
	}

	vector<struct h> h1;
	for (std::map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	{
		struct h h2;
		h2.x=it->first;
		h2.y=it->second;
		h1.push_back(h2);
	}
	sort(h1.begin(),h1.end(),comparey);
	sort(h.begin(),h.end(),comparex);

	int j=0;
	i=0;

	while(i!=h1.size()){
		vector<int> a=index(h,h1,i);
		sort(h.begin()+a[0],h.begin()+a[1]+1,comparey);
		if(a[1]-a[0]>=1){
			answer.push_back(h[a[0]].z);
			answer.push_back(h[a[0]+1].z);
		}
		else answer.push_back(h[a[0]].z);
		i++;
	}

	return answer;
}