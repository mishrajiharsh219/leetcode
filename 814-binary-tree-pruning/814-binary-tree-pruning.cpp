  // the idea is to use DFS to traverse the tree
    // if the current subtree satifies one of the following conditions
    // 1. root value is 1
    // 2. left sub tree contains 1 
    // 3. right sub tree contains 1
    // then we return `root`
    // otherwise, we return nullptr
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
//remove only those which have zero value and no left and right subtree
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        
       root->left=pruneTree(root->left);               //postorder traversal
        root->right=pruneTree(root->right);            //firstly left,then right the root
        
        if(!root->left and !root->right and !root->val){
            return NULL;
        }
        else
            return root;
    }
};