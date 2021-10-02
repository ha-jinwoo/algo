#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> attributes;
    unordered_map<string,int> attributes2;
	for(int i = 0; i < participant.size(); i++)attributes[participant[i]]++;
    for(int i = 0; i < completion.size(); i++)attributes2[completion[i]]++;
	for(auto it=attributes.begin();it!=attributes.end();it++)
		        if(attributes[it->first]!=attributes2[it->first])answer = it->first;
    return answer;
}