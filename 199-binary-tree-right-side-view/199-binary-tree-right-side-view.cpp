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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*>q;
        if(root == nullptr){
            vector<int>emp;
            return emp;
        }
        q.push(root);
        while(!q.empty()){
            TreeNode* last = nullptr;
            int nodes = q.size();
            for(int i = 0 ; i < nodes ; i++){
              last = q.front();
              q.pop();
              if(last->left){
                q.push(last->left);
              }
               if(last->right){
                q.push(last->right);
              }
            }
            result.push_back(last->val);
        }
         return result;
    }
};