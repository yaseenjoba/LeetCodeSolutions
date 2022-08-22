/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     static vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int>currentPath;
    sol(root ,0 , sum, allPaths , currentPath);
    return allPaths;
  }
  private:
 static void sol(TreeNode* root , int sum , int target,  vector<vector<int>>&allPaths , vector<int>&currentPath){
    if(root == NULL)return;

    if(root->val + sum == target && root->left == nullptr && root->right == nullptr){
      currentPath.push_back(root->val);
      allPaths.push_back(currentPath);
      currentPath.pop_back();
      return;
    }
    currentPath.push_back(root->val);
    sol(root->left , sum + root->val , target , allPaths , currentPath);
    sol(root->right , sum + root->val , target , allPaths , currentPath);
    currentPath.pop_back();
 }
};