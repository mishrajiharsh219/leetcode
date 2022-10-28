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
    void revinorder(TreeNode* root,int &value){
        if(root){
            revinorder(root->right,value);
            root->val+=value;
            value=root->val;
            revinorder(root->left,value);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int value=0;
        revinorder(root,value);
        return root;
    }
};