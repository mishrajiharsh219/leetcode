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
    int maxDepth(TreeNode* root) {
             if(root==NULL){
                 return 0;
             } 
        int count=1,countleft=1,countright=1;
        if(root->left)
        countleft+=maxDepth(root->left);
        if(root->right)
        countright+=maxDepth(root->right);
        count=max(countleft,countright);
        return count;
    }
};