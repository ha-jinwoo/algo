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

string solution(string s) {
    string answer = "";
    vector<string> ss = split(s);
    vector<int> a;
    for(string k : ss)a.push_back(stoi(k));
    sort(a.begin(),a.end());
    return answer+to_string(a[0])+' '+to_string(a[a.size()-1]);
}