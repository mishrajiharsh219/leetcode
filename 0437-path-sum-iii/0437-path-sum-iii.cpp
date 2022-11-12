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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return ans;
    }
    void dfs(TreeNode* root,long long int sum){
        if(root==NULL)
            return;
        if(sum==root->val)
            ans+=1;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};