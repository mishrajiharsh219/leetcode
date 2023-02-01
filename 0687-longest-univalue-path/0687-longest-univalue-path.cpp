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
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        dfs(root,ans);
        return ans;
    }
    int dfs(TreeNode* root,int &ans){
     int l=0,r=0;
        if(root->left)
          l=dfs(root->left,ans);
        if(root->right)
            r=dfs(root->right,ans);
        if(root->left and root->left->val==root->val){
         l=l+1;
        }else l=0;
       if(root->right and root->right->val==root->val){
         r=r+1;
        } 
        else r=0;
        ans=max(ans,l+r);
        return max(l,r);
    }
};