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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth==1){
            TreeNode *newnode= new TreeNode(val);        
            newnode->left=root;                          
            return newnode;
        }

        int lvl=1;                                    
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){     
                auto curr= q.front();
                q.pop();

                if(lvl+1==depth){                         
                    TreeNode* nl=new TreeNode(val);      
                    TreeNode* nr=new TreeNode(val);      

                    nl->left=curr->left;                 
                    nr->right=curr->right;              

                    curr->left=nl;                       
                    curr->right=nr;
                }

                if(curr->left) q.push(curr->left);       
                if(curr->right) q.push(curr->right);     
            }
            lvl++;                                      
        } 

        return root;  
    }
};