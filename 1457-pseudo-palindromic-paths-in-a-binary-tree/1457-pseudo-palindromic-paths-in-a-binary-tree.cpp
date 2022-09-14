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
    int dfs(TreeNode * root, vector<int>&v , int levels){
        if(root == NULL){
            return 0;
        }
        v[root->val]++;
        int res = 0;
        if(root->left == NULL && root->right == NULL){
            if(levels&1){
                int ans = 0;
                for(auto &i : v){
                    if(i == levels){
                        res  = 1;
                        break;
                    }
                    if(i%2 != 0){
                        ans++;
                    }        
                }
               if(ans > 1)res =  0;
               else res = 1;
            }else{
                 int ans = 0;
                for(auto &i : v){
                    if(i == levels)res =  1;
                    if(i%2 != 0){
                        ans++;
                    }        
                }
               if(ans > 0)res = 0;
               else res= 1;   
            }
        }
        int ans1 = dfs(root->left , v , levels + 1);
        int ans2 = dfs(root->right , v , levels + 1);
        v[root->val]--;
        return ans1 + ans2 + res;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10 , 0);
        return dfs(root ,v , 1);   
    }
};