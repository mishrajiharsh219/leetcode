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
    int sum=0;
    void sumleaves(TreeNode* root,bool left) {
        if(root){
        sumleaves(root->left,true);
            if(!root->left and !root->right){
                if(left==true)
                    sum+=root->val;
            }
        sumleaves(root->right,false);
        }  
    }
     int sumOfLeftLeaves(TreeNode* root) {
         if(root==NULL)
             return 0;
         sumleaves(root,false);
         return sum;
     }
};