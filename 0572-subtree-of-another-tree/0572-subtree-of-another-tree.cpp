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
    bool checksame(TreeNode* root1, TreeNode* root2){
        if(root1==NULL and root2==NULL)
            return true;
          if(root1==NULL or root2==NULL)
              return false;
      if(root1->val==root2->val and checksame(root1->left,root2->left) and checksame(root1->right,root2->right))
          return true;
        else
            return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==NULL or subroot==NULL){
            return root==subroot;
        }
        if(root->val==subroot->val){
            if(checksame(root,subroot))
                return true;
        }
           if(isSubtree(root->left,subroot) or isSubtree(root->right,subroot))
              return true;
         else
        return false;
    }
};