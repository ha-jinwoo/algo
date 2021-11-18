#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        int maxcount = 0;
        for(int i = 0; i<s.length(); i++){
            unordered_map<char,int> attributes;
            int count = 1;
            attributes[s[i]]++;
            for(int j = i+1; j<s.length(); j++){
                if(attributes[s[j]] > 0) break;
                attributes[s[j]]++;
                count++;
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};