#include <bits/stdc++.h>
using namespace std;
bool space(char c){return isspace(c);}
bool not_space(char c){return !isspace(c);}
vector<string> split(const string& str){
    vector<string> ret;
    string::const_iterator it_b = str.begin();
    while (it_b != str.end()){
        it_b = find_if(it_b, str.end(), not_space);
        string::const_iterator it_e = find_if(it_b, str.end(), space);
        if (it_b != str.end()) ret.push_back(string(it_b, it_e));
        it_b = it_e;
    }
    return ret;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<vector<string>>record2;
    for(int i = 0; i<record.size(); i++) record2.push_back(split(record[i]));
    for(int i = 0; i<record2.size(); i++) if(record2[i][0] != "Leave") m[record2[i][1]] = record2[i][2];
    for(int i=0;i<record2.size();i++){
    	if(record2[i][0]=="Enter"){
    		string s= "";
    		s+=m[record2[i][1]];
    		s+="님이 들어왔습니다.";
    		answer.push_back(s);
    	}
    	else if(record2[i][0]=="Leave"){
    		string s= "";
    		s+=m[record2[i][1]];
    		s+="님이 나갔습니다.";
    		answer.push_back(s);
    	}
    }
    return answer;
}