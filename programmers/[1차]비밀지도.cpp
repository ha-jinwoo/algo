#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> a;
    vector<string> b;
    for(int i = 0; i<arr1.size(); i++){
        string s= "";
        while(arr1[i]!=0){
            s = to_string(arr1[i]%2)+s;
            arr1[i]/=2;
        }
        while(s.size()!=n){
            s="0"+s;
        }
        a.push_back(s);
        s= "";
        while(arr2[i]!=0){
            s = to_string(arr2[i]%2)+s;
            arr2[i]/=2;
        }
        while(s.size()!=n){
            s="0"+s;
        }
        b.push_back(s);
    }
    for(int i = 0; i<a.size(); i++){
        string s= "";
        for(int j =0; j<n;j++){
            if(a[i][j] == '1'||b[i][j]=='1')s+="#";
            else s+=" ";
        }
        answer.push_back(s);
    }
    return answer;
}