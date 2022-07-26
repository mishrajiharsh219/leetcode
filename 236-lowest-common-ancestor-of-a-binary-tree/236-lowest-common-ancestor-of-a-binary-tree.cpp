// method 1
//find the root to P and Q path and lasst common node is LCA
//method 2
//the node returning true from both the p and q is the LCA
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root->val==p->val or root->val==q->val)//if root is either p or q
           return root;
        if(!root->left and !root->right)//if p and q doesnt exist
            return NULL;
        TreeNode *left=NULL,*right=NULL;
        if(root->left)
                left=lowestCommonAncestor(root->left,p,q);
        if(root->right)
                right=lowestCommonAncestor(root->right,p,q);
        if(left and right)
                 return root;
        if(left==NULL)
           return right;
        else
            return left;
    }
};