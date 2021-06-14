#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> a(nums.size());
//         for(int i = 0; i<nums.size(); i++){
//           a[(i+k)%nums.size()] = nums[i];
//         }
//         nums.swap(a);
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

int main(){
  
}