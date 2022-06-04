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
    map<TreeNode* , bool>mm;
    int ans = 0;
    void dfs(TreeNode* root, int low, int high){
        if(root == NULL)return;
        if(mm[root])return;
        if(root->val >=low && root->val <=high)
            ans+=root->val;
        mm[root] = true;
        rangeSumBST(root ->left , low , high);        
        rangeSumBST(root ->right , low , high);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root , low , high);
        return ans;
    }
};