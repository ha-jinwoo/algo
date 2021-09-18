#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;
int answer = 0;
vector <set<int>> vecset;
bool p(set<int> bb){
	for(int i=0;i<vecset.size();i++){
		set<int> s = vecset[i];
		set<int> ss(bb);
		for(int j : s)ss.insert(j);
		if(ss.size()==bb.size())return false;
	}
	return true;
}
void combination(int kn,int kr,vector<vector<string>> relation){
		vector<int> n;
		vector<int> ind;

		for(int i=0; i<kn; i++) n.push_back(i+1);

		for(int i=0; i<kr; i++) ind.push_back(1);
		for(unsigned int i=0; i<n.size()-kr; i++) ind.push_back(0);
		sort(ind.begin(), ind.end());
		do{
			set <string> se;
			vector<int>b;

			for(unsigned int i=0; i<ind.size(); i++) if(ind[i] == 1) b.push_back(n[i]-1);
			for(unsigned int i=0;i<relation.size();i++){
				string s="";
				for(int j : b){
					s+='#';
					s+=relation[i][j];
				}
				se.insert(s);
			}
			if(se.size()==relation.size()){
				set<int>bb;
				for(int i :b)bb.insert(i);
				if(vecset.size()==0) vecset.push_back(bb);
				else if(p(bb)) vecset.push_back(bb);
			}
		}while(next_permutation(ind.begin(), ind.end()));
		answer=vecset.size();
}
int solution(vector<vector<string>> relation) {
    int kn=relation[0].size();
    for(int i=1;i<=kn;i++)
    combination(kn,i,relation);
    return answer;
}

int main(){
	vector<vector<string>> relation={{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
	cout<<solution(relation);
}