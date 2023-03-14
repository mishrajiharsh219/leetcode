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
    int solve(TreeNode* root,int sum)
    {
          if(root->left==NULL and root->right==NULL)
           return sum*10+root->val;
         int ans=0;
        if(root->left)
        ans+=solve(root->left,sum*10+root->val);
        if(root->right)
        ans+=solve(root->right,sum*10+root->val);
        return ans;
        
    }
    int sumNumbers(TreeNode* root) {
       if(root->left==NULL and root->right==NULL)
           return root->val;
        int ans=0;
        if(root->left)
        ans+=solve(root->left,root->val);
        if(root->right)
        ans+=solve(root->right,root->val);
        return ans;
    }
};