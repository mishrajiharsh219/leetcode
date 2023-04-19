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
    int ans=0;
    void solve(TreeNode* root,bool left,int curlen)
    {
        if(root==NULL)
            return ;
        ans=max(ans,curlen);
        if(left==true and root->right)
        {
            solve(root->right,false,curlen+1);
        }
        if(left==true and root->left)
        {
            solve(root->left,true,1);
        }
        if(left==false and root->right)
        {
            solve(root->right,false,1);
        }
        if(left==false and root->left)
        {
            solve(root->left,true,curlen+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root->left==NULL and root->right==NULL)
            return 0;
        if(root->left)
        solve(root->left,true,1);
        if(root->right)
        solve(root->right,false,1);
        return ans;
    }
};