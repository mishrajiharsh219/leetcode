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
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    void dfs(TreeNode* root){
        if(root==NULL)
            return;
        dfs(root->left);
        
        if(prev and (root->val<prev->val)){
         if(first==NULL){
           first=prev;
          mid=root;   
         }
        else
            last=root;
        }
        prev=root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        if(first and last)
        swap(first->val,last->val);
        else
            swap(first->val,mid->val);
    }
};