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
    bool dfs(TreeNode* root, long long int left, long long int right){
        if(root==NULL)
            return true;
        if(root->val >= right || root->val <= left)
            return false;
         if(dfs(root->left, left, root->val) && dfs(root->right, root->val, right) )
            return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root , LLONG_MIN, LLONG_MAX);
        
    }
};