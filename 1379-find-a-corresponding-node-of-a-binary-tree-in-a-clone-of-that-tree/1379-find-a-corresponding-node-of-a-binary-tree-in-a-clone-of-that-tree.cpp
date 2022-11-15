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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(target==NULL)
            return NULL;
        if(original==NULL)
            return NULL;
        if(original==target){
            return cloned;
        }
        TreeNode* lefty=getTargetCopy(original->left,cloned->left,target);
        TreeNode* righty=getTargetCopy(original->right,cloned->right,target);
        if(lefty==NULL and righty==NULL)
            return NULL;
        if(lefty==NULL)
        return righty;
        return lefty;
    }
};