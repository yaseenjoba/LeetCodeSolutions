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
    void sol(TreeNode* root1, TreeNode* root2 , TreeNode* ans)
    {
        if(root1 == NULL &&  root2 ==NULL)return;
        ans->val = ((root1 != NULL )?root1->val : 0) + ((root2 != NULL) ?root2->val : 0);
         TreeNode* myleft = new TreeNode(-1e5);
        ans->left = myleft;
        TreeNode* myright  = new TreeNode(-1e5);
        ans->right = myright;
        
        sol((root1 != NULL ?root1->left : NULL) , (root2 != NULL ?root2->left : NULL) , myleft);  
        if(ans->left -> val == -1e5) ans->left =NULL;
        sol((root1 != NULL ?root1->right : NULL) , (root2 != NULL ?root2->right : NULL) , myright);
        if(ans->right -> val == -1e5) ans->right =NULL;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 ==NULL && root2 == NULL)return NULL;
        TreeNode* ans  = new TreeNode();
        sol(root1 , root2 , ans);
        return ans;
    }
};