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
    int lowlvl=0,ans=0;
    void dfs(TreeNode* curr,int lvl){
        if(lvl>lowlvl){
            lowlvl=lvl;
            ans=curr->val;
        }
        if(curr->left){
            dfs(curr->left,lvl+1);
        }
        if(curr->right){
        dfs(curr->right,lvl+1);
    }
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return root->val;
        if(root->left==NULL and root->right==NULL)
            return root->val;
        dfs(root,0);
        return ans;
    }
};