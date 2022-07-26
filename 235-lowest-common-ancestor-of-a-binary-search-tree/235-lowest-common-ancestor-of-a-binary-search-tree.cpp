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
        if(root->val==p->val or root->val==q->val)
            return root;
        if(root->left==NULL and root->right==NULL)
            return NULL;
         TreeNode* curr=root;
        while(true){
            if(curr->val>p->val and curr->val>q->val){
                curr=curr->left;
            }
            else if(curr->val<p->val and curr->val<q->val)
                curr=curr->right;
            else break;
        }
        return curr;
    }
};


