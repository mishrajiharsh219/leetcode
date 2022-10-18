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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right);
    }
    void helper(TreeNode* root,int &diameter){
        if(root==NULL)
            return;
        int left=height(root->left);
        int right=height(root->right);
        
        diameter=max(diameter,left+right);
        
        helper(root->left,diameter);
        helper(root->right,diameter);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int diameter=0;
     helper(root,diameter);
        return diameter;
    }
    
};