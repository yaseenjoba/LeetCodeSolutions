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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*>q;
        
        if(root == nullptr){
            vector<vector<int>>emp;
            return emp;
        }
        q.push(root);
        bool zigZag = false;
        while(!q.empty()){
          int nodes = q.size();
          vector<int>currentLevel(nodes);
          for(int i = 0 ; i < nodes ;i++){
            TreeNode* t = q.front();
            q.pop();
            if(t->left){
              q.push(t->left);
            }
            if(t->right){
              q.push(t->right);
            }
            if(!zigZag){
                currentLevel[i] = t->val;
            }else currentLevel[nodes - i - 1] = t->val;
          }
          result.push_back(currentLevel);
          zigZag = !zigZag;
        }
        return result;
    }
};