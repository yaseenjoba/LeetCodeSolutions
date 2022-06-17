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
    void dfs(TreeNode* root , int &pos  , int & res, int k){
        if(root == NULL)return;
        dfs(root->left , pos , res , k);
        if(pos == k){
            res = root->val;
        }
        pos++;
        dfs(root->right , pos , res , k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int pos = 1 , res = 0;
        dfs(root , pos , res, k);
        return res;
    }
};