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
    int ans = 0;
    void dfs(TreeNode* root , int x){
        if(root == NULL)return;
        ans = max(ans ,x);
        dfs(root->left , x + 1);       
        dfs(root->right , x + 1);

    }
    int res = 0;
    void doit(TreeNode* root){
        if(root ==NULL)return;
        ans = 0;
        dfs(root->left , 1);
        int t = ans;
        ans = 0;
        dfs(root->right , 1);
        res = max(res , t + ans);
        doit(root->left);        
        doit(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        doit(root);
        return res;

    }
};