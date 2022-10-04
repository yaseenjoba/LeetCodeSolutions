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
    int t;
    bool dfs(TreeNode* root, int sum){
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL && sum+root->val == t)return true;
        return dfs(root->left , sum + root->val) ||  dfs(root->right ,  sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        if(root==NULL)return false;
        if(root->left == NULL && root->right == NULL && root->val == t)return true;
        return dfs(root , 0);
    }
};