#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int solution(string s) {

    int answer = 2100000000;
    n=s.size();
    int i=0;
    int count=0;
    int length=1;

    if(n==1) return 1;

    while(length<n/2+1){
        i=0;
        count=0;

    while(i<n){
        string s1 = s.substr(i,length);
        int j=i+length;
        int count2=1;
        while(j<n){
            if(s1!=s.substr(j,length)) break;
            j=j+length;
            count2++;
        }

        string s2=to_string(count2);

        if(i+length!=j){count=count+s2.size()+length;i=j;}
        else {count=count+length;i=i+length;}
        if(i+length>=n){count=count+n-i;break;}
    }

    answer=min(count,answer);
    length++;
    }

    answer=min(n,answer);
    return answer;
}

int main(){
    string s;
    cin>>s;
    cout<<solution(s);
    return 0;
}
