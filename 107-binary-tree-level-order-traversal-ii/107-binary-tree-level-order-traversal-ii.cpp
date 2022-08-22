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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<vector<int>> result = deque<vector<int>>();
        queue<TreeNode*>q;
        if(root == NULL){
            vector<vector<int>>s;
            return s;
        }
        q.push(root);
        while(!q.empty()){
          int nodes = q.size();
          vector<int>currentLevel;
          for(int i = 0 ; i < nodes ;i++){
            TreeNode* t = q.front();
            q.pop();
            if(t->left){
              q.push(t->left);
            }
            if(t->right){
              q.push(t->right);
            }
            currentLevel.push_back(t->val);
          }
          result.push_front(currentLevel);
        }
        vector<vector<int>>t(result.begin() , result.end());
        return t;
    }
};