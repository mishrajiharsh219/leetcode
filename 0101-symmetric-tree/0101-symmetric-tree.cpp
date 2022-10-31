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
    bool isSymmetric(TreeNode* root) {
      if(root==NULL)
          return true;
        return helper(root->left,root->right);
    }
    bool helper(TreeNode* &lefty,TreeNode* &righty){
        if(lefty==NULL or righty==NULL){
            return (lefty==righty);
        }
        if(lefty->val!=righty->val){
            return false;
        }
        return (helper(lefty->left,righty->right) and helper(lefty->right,righty->left));
    }
};