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
    int ans=1;
    void dfs(TreeNode* curr,int max){
           if(curr->val>=max){
            ans++;
            max=curr->val;
        }
        if(curr->left==NULL and curr->right==NULL)
        {
            return;
        }
     
        if(curr->left!=NULL){
            dfs(curr->left,max);
        }
         if(curr->right!=NULL){
            dfs(curr->right,max);
        }
        
    }
    int goodNodes(TreeNode* root) {
    if(root==NULL)
        return 0;
        if(root->left==NULL and root->right==NULL)
            return ans; 
        if(root->left!=NULL)
        dfs(root->left,root->val);
        if(root->right!=NULL)
        dfs(root->right,root->val);
        return ans;
    }
};