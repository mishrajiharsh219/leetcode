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
    TreeNode* toright(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* delete1(TreeNode* root){
        if(root->left==NULL and root->right==NULL)
            return NULL;
        if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        
        TreeNode* left=root->left;
        TreeNode* rightestleft=toright(root->left);
        rightestleft->right=root->right;
        root=left;
       return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
    TreeNode* dummy=root;
        if(root==NULL)
        return NULL;
     
        if(root and root->left)
    root->left=trimBST(root->left,low,high);
       if(root and root->right)
        root->right=trimBST(root->right,low,high);   
         if(root->val<low or root->val>high){
          root= delete1(root);
      }
     return root;   
    }
};