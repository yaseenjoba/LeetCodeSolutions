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
    map<int ,int>freq;    
    map<TreeNode* ,bool>mm;
    void dfs(TreeNode* root){
        if(root == NULL)return;
        if(mm[root])return;
        cout<<root->val<<endl;
        freq[root->val]++;
        mm[root] = true;
        dfs(root->left );        
        dfs(root->right);

    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        for(auto i : freq){
            // cout<<i.first<<endl;
            int j = k - i.first;
            if(i.first == j && i.second >=2)return true;
            if(i.first != j&& freq.count(j))return true;
        }
        return false;
    }
};