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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode* root=new TreeNode(preorder[0]);
        int i=1;
        root->left=helper(i,root->val,preorder);
        root->right=helper(i,INT_MAX,preorder);
        return root;
    }
    TreeNode* helper(int &i,int upperbound,vector<int> &preorder){
       if(i==preorder.size() or preorder[i]>upperbound)
           return NULL;
      
       TreeNode* root=new TreeNode(preorder[i]);
        i++;
       root->left=helper(i,root->val,preorder);
        root->right=helper(i,upperbound,preorder);
        return root;
    }
};