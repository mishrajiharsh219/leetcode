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
    
    void dfs(TreeNode* root,vector<int> &arr){
   if(root==NULL)
       return;
    if(root->left==NULL and root->right==NULL)
        arr.push_back(root->val);
     dfs(root->left,arr);
    dfs(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> one;
        vector<int> two;
        dfs(root1,one);
        dfs(root2,two);
        if(one==two)
            return true;
        return false;
    }
};