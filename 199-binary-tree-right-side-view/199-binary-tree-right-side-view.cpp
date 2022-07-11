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
        vector<int>ans;
        if(root==NULL)return ans;
        queue<pair<TreeNode* , int>>q;
        q.push({root , 0});
        map<int , vector<int>>level;
        while(!q.empty()){
            pair<TreeNode* , int> s = q.front();
            q.pop();
            level[s.second].push_back((s.first)->val);
            if((s.first)->left!=NULL)
                q.push({(s.first)->left , s.second + 1});
             if((s.first)->right!=NULL)
                q.push({(s.first)->right , s.second + 1});
        }
        for(int i =0 ; i < 300 ;i++){
            if(!level.count(i))break;
            ans.push_back(level[i].back());
        }
        return ans;
    }
};