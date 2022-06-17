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
    set<int>s;
    void dfs(TreeNode* root){
        if(root == NULL)return;
        dfs(root->left);
        s.insert(root->val);
        dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if(s.size() == 1)return -1;
        return *next(s.begin() , 1);
    }
};