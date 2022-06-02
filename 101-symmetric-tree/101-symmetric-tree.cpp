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
    map<TreeNode* , bool>vis;
    vector<int>vleft,vright;
    void leftdfs(TreeNode* node){
        if(vis[node] || node == NULL){
            if(node == NULL){
                vleft.push_back(-1);
            }
                return;
        }
        vis[node] = true;
        vleft.push_back(node->val);
        leftdfs(node ->left);        
        leftdfs(node ->right);
    }
    void rightdfs(TreeNode* node){
         if(vis[node] || node == NULL){
            if(node == NULL){
                vright.push_back(-1);
            }
            return;
        }
        vis[node] = true;
        vright.push_back(node->val);
        rightdfs(node ->right);
        rightdfs(node ->left);        
    }
    bool isSymmetric(TreeNode* root) {
        leftdfs(root ->left);  
        vis.clear();
        rightdfs(root ->right);
        for(auto i : vleft)cout<<i<<" ";
        cout<<endl;
        for(auto i : vright)cout<<i<<" ";
        cout<<endl;
        return vleft == vright;

    }
};