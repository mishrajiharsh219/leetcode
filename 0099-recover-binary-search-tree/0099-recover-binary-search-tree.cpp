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
    vector<int> inorder;
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(inorder.begin(),inorder.end());
        int i=0;
        check(root,inorder,i);
    }
    void check(TreeNode* root, vector<int> &in,int &i){
        if(root->left)
        check(root->left,inorder,i);
        if(root->val!=inorder[i])
            root->val=inorder[i];
        i++;
        if(root->right)
        check(root->right,inorder,i);
    }
    void dfs(TreeNode* root){
        if(root->left)
            dfs(root->left);
        inorder.push_back(root->val);
        if(root->right)
            dfs(root->right);
    }
};