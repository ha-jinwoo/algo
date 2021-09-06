#include<bits/stdc++.h>

using namespace std;

string ext(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> attributes;
    unordered_map<string,int> attributes2;
	  for(int i = 0; i < participant.size(); i++)attributes[participant[i]]++;
    for(int i = 0; i < completion.size(); i++)attributes2[completion[i]]++;
	  for(auto it=attributes.begin();it!=attributes.end();it++)
		    if(attributes[it->first]!=attributes2[it->first])answer = it->first;
    return answer;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> a;
    string s2 = "";
    int start,end;
    for(int i = 1; i<s.size()-1; i++){
        if(s[i] == '{') s2="";
        else if(s[i] == ',') s2+=',';
        else if(s[i] == '}') a.push_back(s2);
        else s2+=s[i];
    }
    vector<vector<string>> c;
    for(int i = 0; i<a.size(); i++){
        vector<string> b = split(a[i],',');
        vector<string> d;
        for(int j = 0; j<b.size(); j++){
            d.push_back(b[j]);
        }
        c.push_back(d);
    }
    vector<string> ans;
    for(int cnt = 1; cnt<=c.size(); cnt++){
        for(int i = 0; i<c.size(); i++){
            if(cnt == c[i].size()){  
                string asdf = ext(c[i],ans);
                ans.push_back(asdf);
                answer.push_back(stoi(asdf));
                break;
            }
        }
    }
    return answer;
}