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
    TreeNode* head;
    void dfs(TreeNode* root ){
        if(root == NULL)return;
        dfs(root->right);
        dfs(root->left);        
        root->right = head;
        root->left = NULL;
        head = root;
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};