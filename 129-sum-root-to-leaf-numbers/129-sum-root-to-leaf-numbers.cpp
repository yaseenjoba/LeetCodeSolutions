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
     static int dfs(TreeNode* root , int sum){
        if(root == NULL)return 0;
        if(root->left  == NULL && root->right == NULL){
          int ans = 10*sum + root->val;
          return ans;
        }
         return  dfs(root->left , 10*sum + root->val) + dfs(root->right , 10*sum + root->val);
     }
    int sumNumbers(TreeNode* root) {
         return dfs(root , 0);
    }
};