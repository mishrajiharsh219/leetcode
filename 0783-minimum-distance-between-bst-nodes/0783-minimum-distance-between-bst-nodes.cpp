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
public:int ans=INT_MAX;
    void helper(TreeNode* &root,int &val,int &ans){
        if(root->left){
            helper(root->left,val,ans);
        }
        if(val>=0)
            ans=min(ans,abs(val-root->val));
        
            val=root->val;
        if(root->right){
            helper(root->right,val,ans);
        }
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        int val=-1;
        helper(root,val,ans);
        return ans;
    }
};