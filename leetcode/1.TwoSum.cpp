#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> res;
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             int diff = target - nums[i];
//             auto itr = res.find(diff);
//             if (itr != res.end()) 
//                 return {res[diff], i};
//             else
//                 res[nums[i]] = i;
            
//         }
//         return {};
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> res;
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             int diff = target - nums[i];
//             auto itr = res.find(diff);
//             if (itr != res.end()) 
//                 return {res[diff], i};
//             else
//                 res[nums[i]] = i;
            
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    result.push_back(i); 
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {2,7,11,15};
  vector<int> result = sol.twoSum(nums, 9);
  for(int i : result) cout<<i<<" ";
}