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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL or root2==NULL){
            if(root1==root2)
                return NULL;
             else if(root1==NULL)
                 return root2;
            else
                return root1;
        }
        TreeNode* newroot=new TreeNode();
        if(root1 and root2){
            newroot->val=root1->val+root2->val;
        }
        newroot->left=mergeTrees(root1->left,root2->left);
        newroot->right=mergeTrees(root1->right,root2->right);
        return newroot;
    }
};