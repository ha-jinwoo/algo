#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool o(string u){
	if(u=="")return true;
	int count1=0;
	for(int i=0;i<u.size();i++){
		if(u[i]=='(')count1++;
		else count1--;
		if(count1<0)return false;
	}
	return true;
}
string solution(string p) {
	if(p=="")return "";
    string u="",v="";
    int count1=0,count2=0;
    int j;
    for(int i=0;i<p.size();i++){
    	if(p[i]=='('){count1++;u+="(";}
    	else {count2++;u+=")";}
    	if(count1==count2){j=i+1;break;}
    }
    if(j!=p.size())v=p.substr(j,p.size()-j);
    if(o(u)){
    	return u+solution(v);
    }
    
    string uu="";
    uu+="(";
    uu+=solution(v);
    uu+=")";
    u.erase(0,1);
    u.pop_back();
    for(int i=0;i<u.size();i++){
        if(u[i]=='(')uu+=")";
        else uu+="(";
    }
    return uu;
}