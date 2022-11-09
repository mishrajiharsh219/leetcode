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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        TreeNode* node=new TreeNode(val);
        TreeNode* prev,*curr=root;
        while(curr){
        if(curr->val<val){
            prev=curr;
            curr=curr->right;
            
        }
          else  if(curr->val>val){
                prev=curr;
                curr=curr->left;
        }
        }
        if(prev->val>val)
            prev->left=node;
        else
            prev->right=node;
        return root;
    }
};