#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if(root == nullptr) return ret;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
      vector<int> level;
      int n = q.size();
      for(int i = 0; i<n; i++){
        TreeNode* node = q.front();
        q.pop();
        level.push_back(node->val);
        if(node->left != nullptr)q.push(node->left);
        if(node->right != nullptr)q.push(node->right);
      }
      ret.push_back(level);
    }
    
    return ret;
  }
};