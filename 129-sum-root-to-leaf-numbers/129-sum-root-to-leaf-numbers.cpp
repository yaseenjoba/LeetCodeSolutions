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
     static int dfs(TreeNode* root , string str){
       if(root == NULL)return 0;
       if(root->left == NULL && root->right == NULL){
         str+= root->val + '0';
         return stoi(str);
       }

       str+= root->val +'0';
       return  dfs(root->left , str) + dfs(root->right , str);
     }
    int sumNumbers(TreeNode* root) {
         return dfs(root , "");
    }
};