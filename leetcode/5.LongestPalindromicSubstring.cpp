#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int start=0,end=0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(end-start < j-i+1){
                    bool isPal = true;
                    for(int k = 0; k<j-i+1/2; k++){
                        if(s[i+k]!=s[j-k]) {
                            isPal = false;
                            break;
                        }
                    }
                    if(isPal){
                        start = i;
                        end = j;
                    }
                } 
            }
        }
        return s.substr(start,end-start+1);
    }
};