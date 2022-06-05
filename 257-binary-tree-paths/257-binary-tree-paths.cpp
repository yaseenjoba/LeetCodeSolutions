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
    vector<vector<int>>ans;
    void dfs(TreeNode* root,vector<int>v){
        if(root==NULL)return;
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(v);
        }
        dfs(root->left , v);        
        dfs(root->right , v);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        vector<int>c;
        dfs(root , c);
        for(auto v : ans){
            string s = "";
            for(int i = 0 ; i < v.size(); i++){
                s+= to_string(v[i]);
                if(i != v.size() - 1)s+='-',s+='>';
            }
            res.push_back(s);
        }
        return res;
    }
};