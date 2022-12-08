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

    bool helper(vector<TreeNode*>& res, TreeNode* & root, unordered_set<int>& set)
    {
        
        if(root == nullptr)
            return false;
        
        bool del = set.find(root->val) != set.end();
        bool l = helper(res, root->left, set);
        bool r = helper(res, root->right, set);
        
        if(del)
        {
           
            if(!l && root->left)
                res.push_back(root->left);
            if(!r && root->right)
                res.push_back(root->right);
            root = nullptr;
        }
        return del;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        
        vector<TreeNode*> res;
        
        
        bool r = helper(res, root, set);
        if( !r && root)
            res.push_back(root);
        return res;
    }
};