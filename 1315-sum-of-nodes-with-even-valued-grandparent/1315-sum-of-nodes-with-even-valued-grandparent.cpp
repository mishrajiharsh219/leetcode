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
    int ans=0;
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,NULL,NULL);
        return ans;
    }
    void dfs(TreeNode* curr,TreeNode* parent,TreeNode* grandparent){
        if(curr==NULL)
            return;
        if(grandparent!=NULL and (grandparent->val)%2==0)
            ans+=curr->val;
        dfs(curr->left,curr,parent);
        dfs(curr->right,curr,parent);
    }
};