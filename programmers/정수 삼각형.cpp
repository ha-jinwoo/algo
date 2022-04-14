#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> t1) {
	int answer = 0;

	vector<int>a;
	a.push_back(0);
	vector<vector<int>> t2;
	int i=0;
	while(i!=t1.size()){
		t2.push_back(a);
		a.push_back(0);
		i++;
	}

	t2[0][0]=t1[0][0];
	i=1;
	int j;
	while(i!=t1.size()){
		t2[i][0]=t2[i-1][0]+t1[i][0];
		t2[i][i]=t2[i-1][i-1]+t1[i][i];
		j=1;
		while(j!=i)
		{
			t2[i][j]=max(t2[i-1][j-1],t2[i-1][j])+t1[i][j];
			j++;
		}
		i++;
	}
	i=t1.size()-1;
	j=1;
	answer=t2[i][0];
	while(j!=t2[i].size()){
		if(t2[i][j]>answer)answer=t2[i][j];
		j++;
	}
	return answer;
}