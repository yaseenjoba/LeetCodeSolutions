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
    bool check(TreeNode * root){
        if(root == NULL) return false;
        return root->val == 1 || check(root->left) || check(root->right); 
    }
    void dfs(TreeNode* root){
        if(root==NULL)
            return;
        if(check(root->left)){
            dfs(root->left);  
        }else{
            root->left = NULL;
        }
        if(check(root->right)){
            dfs(root->right);
        }else{
            root->right = NULL;
        }
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!check(root)){
            return NULL;
        }
        dfs(root);
        return root;
    }
};