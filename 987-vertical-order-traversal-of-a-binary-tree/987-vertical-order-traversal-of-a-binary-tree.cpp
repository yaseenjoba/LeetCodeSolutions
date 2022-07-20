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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<int , pair<int ,TreeNode*>>>q;
        unordered_map<int , vector<pair<int ,int>>>mm;
        q.push({0 , {0 , root}});
        int mi =INT_MAX , mx =INT_MIN;
        while(!q.empty()){
            TreeNode* u = q.front().second.second;
            int c = q.front().first;
            int r = q.front().second.first; 
            q.pop();
            mi = min(c , mi);         
            mx = max(c , mx);

            mm[c].push_back({r + 1,u->val});
            if(u->left){
                q.push({c - 1 ,{r + 1 , u->left}});
            }
            if(u->right){
                q.push({c + 1 , {r + 1 , u->right}});
            }
        }
        vector<vector<int>>ans;
        for(int i = mi ; i <= mx ; i++){
            sort(mm[i].begin() , mm[i].end());
            vector<int>v;
            for(auto i : mm[i]){
                v.push_back(i.second);
            }
            ans.push_back(v);
        }
        return ans;
        
        
    }
};