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
    map<int , vector<int>>level;
    void bfs(TreeNode* x){
        queue<pair<TreeNode*  ,int>> q;
        q.push({x , 0});
        while (!q.empty()) {
            pair<TreeNode*  ,int> s = q.front(); q.pop();
            if(s.first == NULL)continue;
            level[s.second].push_back((s.first)->val);
            q.push({s.first->left , s.second + 1});        
            q.push({s.first->right , s.second + 1});
        }
    }   
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        vector<vector<int>>ans;
        for(auto i : level){
            ans.push_back(i.second);
        }
        return ans;
    }
};