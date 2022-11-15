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
    int dfs(int idx , TreeNode* root){
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL)return idx;
        return max(dfs(2 * idx  + 1, root->right),
        dfs(2 * idx , root->left));        
    }
    int countNodes(TreeNode* root) {
        return dfs(1 , root);
    }
};