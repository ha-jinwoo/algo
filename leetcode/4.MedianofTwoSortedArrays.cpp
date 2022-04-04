#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), n1 = 0, m1 = 0, index = 0;
        vector<int> nums3(n+m);
        
        while(n1 < n && m1 < m){
            if (nums1[n1] <= nums2[m1]){
                nums3[index++] = nums1[n1++];                       
            }
            else {
                nums3[index++] = nums2[m1++];
            }
        }
        
        for(int i = n1; i<n; i++){
            nums3[index++] = nums1[i];
        }
        for(int i = m1; i<m; i++){
            nums3[index++] = nums2[i];
        }
        
        double ans = 0;
        int a = (m+n) / 2;
        if ((m+n) % 2 == 0){
            ans = nums3[a] + nums3[a-1];
            ans = ans / 2;
        }
        else {
            ans = nums3[a];
        }
        return ans;
    }
};